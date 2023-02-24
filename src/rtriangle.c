#include "internals.h"

#define SWAP(T, A, B) \
  do {                \
    T _tmp = A;       \
    A = B;            \
    B = _tmp;         \
  } while (0)

void
top_triangle(Rysik *rys, int x0, int y0, int x1, int y1, int x2, uint32_t color)
{
  for (int x = x1; x <= x2; ++x) rysik_line(rys, x0, y0, x, y1, color);
}

void
bot_triangle(Rysik *rys, int x0, int y0, int x1, int y1, int x2, uint32_t color)
{
  for (int x = x1; x <= x2; ++x) rysik_line(rys, x0, y0, x, y1, color);
}

void
rysik_triangle(Rysik *rys, int x0, int y0, int x1, int y1, int x2, int y2,
               uint32_t color)
{
  if (y0 > y1) {
    SWAP(int, x0, x1);
    SWAP(int, y0, y1);
  }

  if (y1 > y2) {
    SWAP(int, x1, x2);
    SWAP(int, y1, y2);
  }

  if (y0 > y1) {
    SWAP(int, x0, x1);
    SWAP(int, y0, y1);
  }

  if (y0 == y2) return;

  if (y0 == y1) {
    top_triangle(rys, x0, y0, MIN(x1, x2), y1, MAX(x1, x2), color);
  } else if (y1 == y2) {
    bot_triangle(rys, x0, y0, MIN(x1, x2), y1, MAX(x1, x2), color);
  } else {
    int x3 = x0 + (y1 - y0) * (x2 - x0) / (y2 - y0);
    top_triangle(rys, x0, y0, MIN(x1, x3), y1, MAX(x1, x3), color);
    bot_triangle(rys, x2, y2, MIN(x1, x3), y1, MAX(x1, x3), color);
  }
}
