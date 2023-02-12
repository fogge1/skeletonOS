#include "drivers/screen.h"


void main(void) {
  clear_screen();
  print_str("test2", 0, 0);
  for(;;);
}
