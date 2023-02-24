#include <stdio.h>

#include "rysik.h"

#define WIDTH  800
#define HEIGHT 600

int
main(void)
{
  Rysik *rys;
  rys = rysik_init(WIDTH, HEIGHT);

  rysik_fill(rys, 0xFF0000FF);
  rysik_rect(rys, 100, 100, 200, 300, 0xFFFF0000);
  rysik_rect(rys, 100, 100, 300, 200, 0x6900FF00);
  rysik_circle(rys, 400, 300, 200, 0xAA00FFFF);

  rysik_save_to_ppm(rys, "test.ppm");
  rysik_destroy(rys);
}
