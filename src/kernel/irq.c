#include "io.h"
#include "irq.h"

#define IRQ0_OFFSET     0x20        /* offset of master PIC IRQs */
#define IRQ8_OFFSET     0x28        /* offset of slave PIC IRQs */

extern void _irq0(void);
extern void _irq1(void);
extern void _irq2(void);
extern void _irq3(void);
extern void _irq4(void);
extern void _irq5(void);
extern void _irq6(void);
extern void _irq7(void);
extern void _irq8(void);
extern void _irq9(void);
extern void _irqa(void);
extern void _irqb(void);
extern void _irqc(void);
extern void _irqd(void);
extern void _irqe(void);
extern void _irqf(void);

void *irq_routines[16] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};

void irq_install_handler(uint8_t irq, void (*handler)(struct int_regs *r)) {
  irq_routines[irq] = handler;
}

void irq_uninstall_handler(uint8_t irq) {
  irq_routines[irq] = 0;
}

void irq_remap(void) {
  outportb(0x20, 0x11);
  outportb(0xA0, 0x11);
  outportb(0x21, 0x20);
  outportb(0xA1, 0x28);
  outportb(0x21, 0x04);
  outportb(0xA1, 0x02);
  outportb(0x21, 0x01);
  outportb(0xA1, 0x01);
  outportb(0x21, 0x0);
  outportb(0xA1, 0x0);
}

void irq_install(void) {
  irq_remap();
  
  _idt_set_gate(IRQ0_OFFSET+0, (uint32_t)_irq0, 0x08, 0x8e);
  _idt_set_gate(IRQ0_OFFSET+1, (uint32_t)_irq1, 0x08, 0x8e);
  _idt_set_gate(IRQ0_OFFSET+2, (uint32_t)_irq2, 0x08, 0x8e);
  _idt_set_gate(IRQ0_OFFSET+3, (uint32_t)_irq3, 0x08, 0x8e);
  _idt_set_gate(IRQ0_OFFSET+4, (uint32_t)_irq4, 0x08, 0x8e);
  _idt_set_gate(IRQ0_OFFSET+5, (uint32_t)_irq5, 0x08, 0x8e);
  _idt_set_gate(IRQ0_OFFSET+6, (uint32_t)_irq6, 0x08, 0x8e);
  _idt_set_gate(IRQ0_OFFSET+7, (uint32_t)_irq7, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+0, (uint32_t)_irq8, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+1, (uint32_t)_irq9, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+2, (uint32_t)_irqa, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+3, (uint32_t)_irqb, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+4, (uint32_t)_irqc, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+5, (uint32_t)_irqd, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+6, (uint32_t)_irqe, 0x08, 0x8e);
  _idt_set_gate(IRQ8_OFFSET+7, (uint32_t)_irqf, 0x08, 0x8e);
}

void _irq_handler(struct int_regs r) {
  void (*handler)(struct int_regs *r);

  handler = irq_routines[r.int_no];

  if (handler) {
    handler(&r);
  }

  if (r.int_no >= 40) {
    outportb(0xA0, 0x20);
  }

  outportb(0x20, 0x20);
}
