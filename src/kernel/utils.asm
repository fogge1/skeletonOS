; vim: ft=nasm


[bits 32]

section .text

global _idt_load
extern _idtp

_idt_load:
  lidt [_idtp]
  ret
