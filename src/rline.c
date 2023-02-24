#include "internals.h"

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
  while (true) {
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
