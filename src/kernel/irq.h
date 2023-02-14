#include "stdint.h"

#include "idt.h"

typedef void (*irq_handler_t)(struct int_regs *);

void irq_remap(void);

void irq_handler_install(uint8_t irq, irq_handler_t handler);
void irq_handler_uninstall(uint8_t irq);
void irq_install(void);

