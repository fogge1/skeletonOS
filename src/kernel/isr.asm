; vim: ft=nasm

global _isr00
global _isr01
global _isr02
global _isr03
global _isr04
global _isr05
global _isr06
global _isr07
global _isr08
global _isr09
global _isr0a
global _isr0b
global _isr0c
global _isr0d
global _isr0e
global _isr0f
global _isr10
global _isr11
global _isr12
global _isr13
global _isr14
global _isr15
global _isr16
global _isr17
global _isr18
global _isr19
global _isr1a
global _isr1b
global _isr1c
global _isr1d
global _isr1e
global _isr1f
global _isr80

_isr00:
    cli
    push byte 0x00
    jmp isr_common_stub
_isr01:
    cli
    push byte 0x01
    jmp isr_common_stub
_isr02:
    cli
    push byte 0x02
    jmp isr_common_stub
_isr03:
    cli
    push byte 0x03
    jmp isr_common_stub
_isr04:
    cli
    push byte 0x04
    jmp isr_common_stub
_isr05:
    cli
    push byte 0x05
    jmp isr_common_stub
_isr06:
    cli
    push byte 0x06
    jmp isr_common_stub
_isr07:
    cli
    push byte 0x07
    jmp isr_common_stub
_isr08:
    cli
    push byte 0x08
    jmp isr_common_stub
_isr09:
    cli
    push byte 0x09
    jmp isr_common_stub
_isr0a:
    cli
    push byte 0x0a
    jmp isr_common_stub
_isr0b:
    cli
    push byte 0x0b
    jmp isr_common_stub
_isr0c:
    cli
    push byte 0x0c
    jmp isr_common_stub
_isr0d:
    cli
    push byte 0x0d
    jmp isr_common_stub
_isr0e:
    cli
    push byte 0x0e
    jmp isr_common_stub
_isr0f:
    cli
    push byte 0x0f
    jmp isr_common_stub
_isr10:
    cli
    push byte 0x10
    jmp isr_common_stub
_isr11:
    cli
    push byte 0x11
    jmp isr_common_stub
_isr12:
    cli
    push byte 0x12
    jmp isr_common_stub
_isr13:
    cli
    push byte 0x13
    jmp isr_common_stub
_isr14:
    cli
    push byte 0x14
    jmp isr_common_stub
_isr15:
    cli
    push byte 0x15
    jmp isr_common_stub
_isr16:
    cli
    push byte 0x16
    jmp isr_common_stub
_isr17:
    cli
    push byte 0x17
    jmp isr_common_stub
_isr18:
    cli
    push byte 0x18
    jmp isr_common_stub
_isr19:
    cli
    push byte 0x19
    jmp isr_common_stub
_isr1a:
    cli
    push byte 0x1a
    jmp isr_common_stub
_isr1b:
    cli
    push byte 0x1b
    jmp isr_common_stub
_isr1c:
    cli
    push byte 0x1c
    jmp isr_common_stub
_isr1d:
    cli
    push byte 0x1d
    jmp isr_common_stub
_isr1e:
    cli
    push byte 0x1e
    jmp isr_common_stub
_isr1f:
    cli
    push byte 0x1f
    jmp isr_common_stub

extern exception_handler
isr_common_stub:
    pusha                       ; edi, esi, ebp, esp, ebx, edx, ecx, eax
    mov ax, ds
    push eax                    ; save the data segment, needs to be 4 bytes
                                ; wide because of alignment i presume

    mov ax, 0x10                ; load ring 0 ds
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    cld                         ; SysV ABI requires DF to be clear
                                ; on function entry
    call exception_handler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    popa
    add esp, 4                  ; clean up after int_no

    sti
    iret
