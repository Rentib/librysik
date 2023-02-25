#ifndef RYSIK_H
#define RYSIK_H 1

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct Rysik Rysik;

struct Rysik {
  size_t width;
  size_t height;
  uint32_t *pixels;
};

/**
 * Create a new struct storing a canvas of size \p width by \p height with all
 * pixels initialized to black.
 * \param width - width of canvas;
 * \param height - height of canvas.
 * \return On success, returns pointer to the newly created structure. To avoid
 * memory leak, the returned pointer must be deallocated with
 * rysik_destroy(). On failure, returns a null pointer.
 */
extern Rysik *rysik_init(size_t width, size_t height);

/**
 * Destroys a structure previously created by rysik_init(). If \p rys is a null
 * pointer, the function does nothing.
 * \param rys - pointer to the structure to destroy.
 */
extern void rysik_destroy(Rysik *rys);

/**
 * Saves canvas into a ppm file.
 * \param rys - pointer to the structure storing a canvas to save;
 * \param filename - cstring representing a name of the file.
 * \return On success, returns true. On failure, returns false.
 */
extern bool rysik_save_to_ppm(Rysik *rys, char *restrict filename);

/**
 * Fills whole canvas stored in the structure pointed by \p rys with \p color.
 * \param rys - pointer to the structure storing a canvas;
 * \param color - color in RRGGBBAA format.
 */
extern void rysik_fill(Rysik *rys, uint32_t color);

extern void rysik_rect(Rysik *rys, int x, int y, int width, int height,
                       uint32_t color);
extern void rysik_circle(Rysik *rys, int x, int y, int radius, uint32_t color);
extern void rysik_ellipse(Rysik *rus, int x, int y, int a, int b,
                          uint32_t color);
extern void rysik_line(Rysik *rys, int x0, int y0, int x1, int y1,
                       uint32_t color);
extern void rysik_triangle(Rysik *rys, int x0, int y0, int x1, int y1, int x2,
                           int y2, uint32_t color);

#endif  // RYSIK_H
