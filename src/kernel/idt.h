#ifndef _IDT_H
#define _IDT_H

#include "stdint.h"

#define IDT_SIZE 256


/* argument to all ISRs (including IRQs) */
struct int_regs {
    /* data segment */
    uint32_t ds;
    /* pushed by pusha */
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    /* interrupt number pushed in each isr */
    uint32_t int_no;
    /* pushed automatically on interrupt */
    uint32_t eip, cs, eflags;
};

struct idt_entry {
  uint16_t off_low, sel;
  uint8_t reserved, flags;
  uint16_t off_high;
} __attribute__((packed));

struct idt_ptr {
  uint16_t size;
  struct idt_entry *base;
} __attribute__((packed));

extern struct idt_entry _idt[IDT_SIZE];
extern struct idt_ptr _idtp;

extern void _idt_load();

void _idt_set_gate(uint8_t i, uint32_t offset, uint16_t selector, uint8_t flags);

void idt_install(void);

#endif
