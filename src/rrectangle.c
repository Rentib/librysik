#include "internals.h"

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
