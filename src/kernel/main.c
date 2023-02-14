#include "drivers/screen.h"
#include "isr.h"
#include "idt.h"
#include "irq.h"
#include "timer.h"

void main(void) {
  clear_screen();
  print_str("test2", 0, 0);
  
  idt_install();
  isrs_install();
  irq_install();

  timer_install();

  __asm__ volatile("sti");
  
  //int a = 23;
  //__asm__ volatile("idiv %1, %0" : "=a"(a) : "d"(0));
  
   

  for(;;);
}
