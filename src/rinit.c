#include <stdlib.h>

#include "internals.h"

Rysik*
rysik_init(size_t w, size_t h)
{
  Rysik* r;

  if (!(r = malloc(sizeof(Rysik))) ||
      !(r->pixels = calloc(w * h, sizeof(uint32_t))))
    return NULL;
  r->width = w;
  r->height = h;

  return r;
}
