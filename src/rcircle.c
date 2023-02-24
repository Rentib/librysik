#include "internals.h"

void
rysik_circle(Rysik *rys, int x, int y, int r, uint32_t color)
{
  int rysq = r * r - 1, xsq = r * r;

  horizontal_line(rys, x - r, y, 2 * r, color);
  for (int cx = r, cy = 1; cy <= r; rysq -= ++cy * 2 + 1) {
    while (xsq > rysq ) xsq -= 1 + 2 * cx--;
    horizontal_line(rys, x - cx, y - cy, 2 * cx, color);
    horizontal_line(rys, x - cx, y + cy, 2 * cx, color);
  }
}
