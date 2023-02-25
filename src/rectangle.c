#include "internals.h"

void
rysik_fill(Rysik *rys, uint32_t color)
{
  for (size_t i = 0; i < rys->width * rys->height; ++i) rys->pixels[i] = color;
}

void
rysik_rect(Rysik *rys, int x, int y, int w, int h, uint32_t color)
{
  int lx = MIN(x, x + w);
  w = ABS(w);

  if (lx < 0) {
    w += lx;
    lx = 0;
  }

  for (int ly = MIN(y, y + h), ry = MAX(y, y + h); ly < ry; ++ly)
    horizontal_line(rys, lx, ly, w, color);
}

// Bresenham's line algorithm
// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
void
rysik_line(Rysik *rys, int x0, int y0, int x1, int y1, uint32_t color)
{
  int dx = ABS(x1 - x0);
  int sx = x0 < x1 ? 1 : -1;
  int dy = -ABS(y1 - y0);
  int sy = y0 < y1 ? 1 : -1;
  int err = dx + dy;
  while (1) {
    plot(rys, x0, y0, color);
    if (x0 == x1 && y0 == y1) break;
    int err2 = 2 * err;
    if (err2 >= dy) {
      if (x0 == x1) break;
      err += dy;
      x0 += sx;
    }
    if (err2 <= dx) {
      if (y0 == y1) break;
      err += dx;
      y0 += sy;
    }
  }
}
