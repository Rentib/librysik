#include "../rysik.h"

#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define ABS(A)    ((A) < 0 ? -(A) : (A))

#define RYSIK_RED(C)   (((C) >> (8 * 0)) & 0xFF)
#define RYSIK_GREEN(C) (((C) >> (8 * 1)) & 0xFF)
#define RYSIK_BLUE(C)  (((C) >> (8 * 2)) & 0xFF)
#define RYSIK_ALPHA(C) (((C) >> (8 * 3)) & 0xFF)
#define RYSIK_RGBA(R, G, B, A) \
  (((R) << (8 * 0)) | ((G) << (8 * 1)) | ((B) << (8 * 2)) | ((A) << (8 * 3)))

// lay color c2 over color c1
static inline uint32_t
blend_colors(uint32_t c1, uint32_t c2)
{
  uint32_t r1 = RYSIK_RED(c1);
  uint32_t g1 = RYSIK_GREEN(c1);
  uint32_t b1 = RYSIK_BLUE(c1);
  uint32_t a1 = RYSIK_ALPHA(c1);

  uint32_t r2 = RYSIK_RED(c2);
  uint32_t g2 = RYSIK_GREEN(c2);
  uint32_t b2 = RYSIK_BLUE(c2);
  uint32_t a2 = RYSIK_ALPHA(c2);

  return RYSIK_RGBA(MIN(0xFF, (r1 * (0xFF - a2) + r2 * a2) / 0xFF),
                    MIN(0xFF, (g1 * (0xFF - a2) + g2 * a2) / 0xFF),
                    MIN(0xFF, (b1 * (0xFF - a2) + b2 * a2) / 0xFF),
                    (a1 + a2) >> 1);
}

static inline void
horizontal_line(Rysik *rys, int x, int y, size_t w, uint32_t color)
{
  if (y < 0 || y >= (int)rys->height) return;
  w = x < 0 ? w > (size_t)-x ? w + x : 0 : w;
  x = MAX(x, 0), w = MIN(w, rys->width - x);
  for (uint32_t *pixel = rys->pixels + x + rys->width * y; w--; ++pixel)
    *pixel = blend_colors(*pixel, color);
}

static inline void
plot(Rysik *rys, int x, int y, uint32_t color)
{
  if (0 > x || x >= (int)rys->width || 0 > y || y >= (int)rys->height) return;
  uint32_t *pixel = rys->pixels + x + rys->width * y;
  *pixel = blend_colors(*pixel, color);
}
