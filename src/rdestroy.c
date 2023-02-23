#include "internals.h"

void
rysik_destroy(Rysik *rys)
{
  if (!rys) return;
  free(rys->pixels);
  free(rys);
}
