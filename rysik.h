#ifndef RYSIK_H
#define RYSIK_H 1

#include <stddef.h>
#include <stdint.h>

/** \typedef
 * Typedef for Rysik structure.
 */
typedef struct Rysik Rysik;

/** \struct Rysik
 * Structure storing a canvas.
 */
struct Rysik {
  size_t width;      ///< Width of canvas;
  size_t height;     ///< Height of canvas;
  uint32_t *pixels;  ///< Array storing pixels of canvas in RRGGBBAA format.
};

/**
 * Initializes a new Rysik object representing a canvas of dimensions \p width
 * by \p height with pixels stored in \p pixels. The behavior is undefined if
 * size of array pointer by \p pixels is less than \p width * \p height.
 * \param rys - pointer to the structure storing a canvas;
 * \param width - width of canvas;
 * \param height - height of canvas;
 * \param pixels - pointer to array of pixels.
 * \return On success, returns pointer to the
 * newly created structure. To avoid memory leak, the returned pointer must be
 * deallocated with rysik_destroy(). On failure, returns a null pointer.
 */
extern void rysik_init(Rysik *rys, size_t width, size_t height,
                       uint32_t *pixels);

/**
 * Destroys a structure previously created by rysik_init(). If \p rys is a null
 * pointer, the function does nothing.
 * \param rys - pointer to the structure to destroy.
 */
extern void rysik_destroy(Rysik *rys);

/**
 * Fills whole canvas stored in the structure pointed by \p rys with \p color.
 * \param rys - pointer to the structure storing a canvas;
 * \param color - color in RRGGBBAA format.
 */
extern void rysik_fill(Rysik *rys, uint32_t color);

/**
 * Fills a given rectangle with \p color.
 * \param rys - pointer to the structure storing a canvas;
 * \param x - x coordinate of top left corner;
 * \param y - y coordinate of top left corner;
 * \param width - width of the rectangle;
 * \param height - height of the rectangle;
 * \param color - color in RRGGBBAA format.
 */
extern void rysik_rect(Rysik *rys, int x, int y, int width, int height,
                       uint32_t color);

/**
 * Fills a given circle with \p color.
 * \param rys - pointer to the structure storing a canvas;
 * \param x - x coordinate of circle's center or origin;
 * \param y - y coordinate of circle's center or origin;
 * \param radius - length of circle's radius;
 * \param color - color in RRGGBBAA format.
 */
extern void rysik_circle(Rysik *rys, int x, int y, int radius, uint32_t color);

/**
 * Fills a given ellipse with \p color.
 * \param rys - pointer to the structure storing a canvas;
 * \param x - x coordinate of ellipse's center;
 * \param y - y coordinate of ellipse's center;
 * \param a - length of ellipse's semi-major axis;
 * \param b - length of ellipse's semi-minor axis;
 * \param color - color in RRGGBBAA format.
 */
extern void rysik_ellipse(Rysik *rus, int x, int y, int a, int b,
                          uint32_t color);

/**
 * Draws a segment between two given points.
 * \param rys - pointer to the structure storing a canvas;
 * \param x0 - x coordinate of the first point;
 * \param y0 - y coordinate of the first point;
 * \param x1 - x coordinate of the second point;
 * \param y1 - y coordinate of the second point;
 * \param color - color in RRGGBBAA format.
 */
extern void rysik_line(Rysik *rys, int x0, int y0, int x1, int y1,
                       uint32_t color);

/**
 * Fills a given triangle with \p color.
 * \param rys - pointer to the structure storing a canvas;
 * \param x0 - x coordinate of the first point;
 * \param y0 - y coordinate of the first point;
 * \param x1 - x coordinate of the second point;
 * \param y1 - y coordinate of the second point;
 * \param x2 - x coordinate of the third point;
 * \param y2 - y coordinate of the third point;
 * \param color - color in RRGGBBAA format.
 */
extern void rysik_triangle(Rysik *rys, int x0, int y0, int x1, int y1, int x2,
                           int y2, uint32_t color);

#endif  // RYSIK_H
