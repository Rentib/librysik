#include "internals.h"

void
rysik_init(Rysik *rys, size_t w, size_t h, uint32_t *pixels)
{
  *rys = (Rysik){.width = w, .height = h, .pixels = pixels};
}

void
rysik_destroy(Rysik *rys)
{
  if (!rys) return;
}
