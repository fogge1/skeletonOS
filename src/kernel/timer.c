#include "io.h"
#include "drivers/screen.h"
#include "irq.h"
#include "idt.h"

int timer_ticks = 0;

void timer_handler(struct int_regs *r) {
  timer_ticks++;

  if (timer_ticks % 18 == 0) {
    print_str("One second" ,0, 0);
  }
}

void timer_install() {
  irq_install_handler(0, timer_handler);
}
