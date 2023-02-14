#include "idt.h"

#include "string.h"

struct idt_entry _idt[IDT_SIZE];
struct idt_ptr _idtp;

void _idt_set_gate(uint8_t i, uint32_t offset,
                   uint16_t selector, uint8_t flags) {
    _idt[i].off_low = offset & 0xffff;
    _idt[i].off_high = (offset >> 16) & 0xffff;

    _idt[i].sel = selector;
    _idt[i].reserved = 0;
    _idt[i].flags = flags;
}

void idt_install(void) {
    _idtp.size = (sizeof(struct idt_entry) * IDT_SIZE) - 1;
    _idtp.base = (struct idt_entry *)&_idt;

    /* initialize to zero */
    memset(&_idt, 0, _idtp.size+1);

    _idt_load();
}

