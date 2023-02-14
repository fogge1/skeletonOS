#include "drivers/screen.h"
#include "isr.h"
#include "idt.h"

extern void _isr00(void);
extern void _isr01(void);
extern void _isr02(void);
extern void _isr03(void);
extern void _isr04(void);
extern void _isr05(void);
extern void _isr06(void);
extern void _isr07(void);
extern void _isr08(void);
extern void _isr09(void);
extern void _isr0a(void);
extern void _isr0b(void);
extern void _isr0c(void);
extern void _isr0d(void);
extern void _isr0e(void);
extern void _isr0f(void);
extern void _isr10(void);
extern void _isr11(void);
extern void _isr12(void);
extern void _isr13(void);
extern void _isr14(void);
extern void _isr15(void);
extern void _isr16(void);
extern void _isr17(void);
extern void _isr18(void);
extern void _isr19(void);
extern void _isr1a(void);
extern void _isr1b(void);
extern void _isr1c(void);
extern void _isr1d(void);
extern void _isr1e(void);
extern void _isr1f(void);

void isrs_install(void) {
    /* flag bit 7: present, 6-5: ring, 4: zero, 3-0: type */
    /* type 1110 (0xe) = interrupt gate */
    _idt_set_gate(0x00, (uint32_t)_isr00, 0x08, 0x8e);
    _idt_set_gate(0x01, (uint32_t)_isr01, 0x08, 0x8e);
    _idt_set_gate(0x02, (uint32_t)_isr02, 0x08, 0x8e);
    _idt_set_gate(0x03, (uint32_t)_isr03, 0x08, 0x8e);
    _idt_set_gate(0x04, (uint32_t)_isr04, 0x08, 0x8e);
    _idt_set_gate(0x05, (uint32_t)_isr05, 0x08, 0x8e);
    _idt_set_gate(0x06, (uint32_t)_isr06, 0x08, 0x8e);
    _idt_set_gate(0x07, (uint32_t)_isr07, 0x08, 0x8e);
    _idt_set_gate(0x08, (uint32_t)_isr08, 0x08, 0x8e);
    _idt_set_gate(0x09, (uint32_t)_isr09, 0x08, 0x8e);
    _idt_set_gate(0x0a, (uint32_t)_isr0a, 0x08, 0x8e);
    _idt_set_gate(0x0b, (uint32_t)_isr0b, 0x08, 0x8e);
    _idt_set_gate(0x0c, (uint32_t)_isr0c, 0x08, 0x8e);
    _idt_set_gate(0x0d, (uint32_t)_isr0d, 0x08, 0x8e);
    _idt_set_gate(0x0e, (uint32_t)_isr0e, 0x08, 0x8e);
    _idt_set_gate(0x0f, (uint32_t)_isr0f, 0x08, 0x8e);
    _idt_set_gate(0x10, (uint32_t)_isr10, 0x08, 0x8e);
    _idt_set_gate(0x11, (uint32_t)_isr11, 0x08, 0x8e);
    _idt_set_gate(0x12, (uint32_t)_isr12, 0x08, 0x8e);
    _idt_set_gate(0x13, (uint32_t)_isr13, 0x08, 0x8e);
    _idt_set_gate(0x14, (uint32_t)_isr14, 0x08, 0x8e);
    _idt_set_gate(0x15, (uint32_t)_isr15, 0x08, 0x8e);
    _idt_set_gate(0x16, (uint32_t)_isr16, 0x08, 0x8e);
    _idt_set_gate(0x17, (uint32_t)_isr17, 0x08, 0x8e);
    _idt_set_gate(0x18, (uint32_t)_isr18, 0x08, 0x8e);
    _idt_set_gate(0x19, (uint32_t)_isr19, 0x08, 0x8e);
    _idt_set_gate(0x1a, (uint32_t)_isr1a, 0x08, 0x8e);
    _idt_set_gate(0x1b, (uint32_t)_isr1b, 0x08, 0x8e);
    _idt_set_gate(0x1c, (uint32_t)_isr1c, 0x08, 0x8e);
    _idt_set_gate(0x1d, (uint32_t)_isr1d, 0x08, 0x8e);
    _idt_set_gate(0x1e, (uint32_t)_isr1e, 0x08, 0x8e);
    _idt_set_gate(0x1f, (uint32_t)_isr1f, 0x08, 0x8e);
}

const char *exception_msgs[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
};

void exception_handler(struct int_regs r) {
    if(r.int_no < 32)
      print_str(exception_msgs[r.int_no], 0, 0);
    __asm__ volatile ("cli; hlt"); // Completely hangs the computer
}
