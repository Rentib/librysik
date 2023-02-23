#include "internals.h"

void
rysik_fill(Rysik *rys, uint32_t color)
{
  for (size_t i = 0; i < rys->width * rys->height; ++i) rys->pixels[i] = color;
}
