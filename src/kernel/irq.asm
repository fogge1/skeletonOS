global _irq0
global _irq1
global _irq2
global _irq3
global _irq4
global _irq5
global _irq6
global _irq7
global _irq8
global _irq9
global _irqa
global _irqb
global _irqc
global _irqd
global _irqe
global _irqf

_irq0:
    cli
    push byte 0x0
    jmp irq_common_stub
_irq1:
    cli
    push byte 0x1
    jmp irq_common_stub
_irq2:
    cli
    push byte 0x2
    jmp irq_common_stub
_irq3:
    cli
    push byte 0x3
    jmp irq_common_stub
_irq4:
    cli
    push byte 0x4
    jmp irq_common_stub
_irq5:
    cli
    push byte 0x5
    jmp irq_common_stub
_irq6:
    cli
    push byte 0x6
    jmp irq_common_stub
_irq7:
    cli
    push byte 0x7
    jmp irq_common_stub
_irq8:
    cli
    push byte 0x8
    jmp irq_common_stub
_irq9:
    cli
    push byte 0x9
    jmp irq_common_stub
_irqa:
    cli
    push byte 0xa
    jmp irq_common_stub
_irqb:
    cli
    push byte 0xb
    jmp irq_common_stub
_irqc:
    cli
    push byte 0xc
    jmp irq_common_stub
_irqd:
    cli
    push byte 0xd
    jmp irq_common_stub
_irqe:
    cli
    push byte 0xe
    jmp irq_common_stub
_irqf:
    cli
    push byte 0xf
    jmp irq_common_stub

extern _irq_handler
irq_common_stub:
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
    call _irq_handler

    pop eax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    popa
    add esp, 4                  ; clean up after int_no

    sti
    iret

