#include "internals.h"

void
rysik_circle(Rysik *rys, int x, int y, int r, uint32_t color)
{
  int rysq = r * r - 1, xsq = r * r;

  horizontal_line(rys, x - r, y, 2 * r, color);
  for (int cx = r, cy = 1; cy <= r; rysq -= ++cy * 2 + 1) {
    while (xsq > rysq) xsq -= 1 + 2 * cx--;
    horizontal_line(rys, x - cx, y - cy, 2 * cx, color);
    horizontal_line(rys, x - cx, y + cy, 2 * cx, color);
  }
}

void
rysik_ellipse(Rysik *rys, int x, int y, int a, int b, uint32_t color)
{
  int absq = a * a * b * b, xbsq = absq;
  int asq = a * a, bsq = b * b;
  
  horizontal_line(rys, x - a, y, 2 * a, color);
  for (int cx = a, cy = 1; cy <= b; absq -= (++cy * 2 + 1) * asq) {
    while (xbsq > absq) xbsq -= (1 + 2 * cx--) * bsq;
    horizontal_line(rys, x - cx, y - cy, 2 * cx, color);
    horizontal_line(rys, x - cx, y + cy, 2 * cx, color);
  }
}
