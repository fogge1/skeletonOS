; vim: ft=nasm
[bits 16]

KERNEL_OFFSET equ 0x1000

_lowstart:
xor ax, ax
mov ds, ax
mov es, ax
mov ss, ax

push 0
push _highstart
retf
_highstart:


mov bx, HELLO_MSG
call print

mov [BOOT_DRIVE], dl

mov bp, 0x9000
mov sp, bp

;mov bx, 0x9000
;mov dh, 5
;mov dl, [BOOT_DRIVE]
;call disk_load

call load_kernel

call switch_to_pm

jmp $

print:
  mov ah, 0x0e
  pusha
  jmp print_string

print_string:

  mov al, [bx]
  add bx, 1
  int 0x10 ; write character

  cmp al, 0x0 ; compare if al = 0
  jne print_string ; if not jump to print_string
  popa ; 
  ret

%include "src/boot/print_hex.asm"
%include "src/boot/gdt.asm"

disk_load:
  push dx

  mov ah, 0x02
  mov al, dh
  mov ch, 0x00
  mov dh, 0x00
  mov cl, 0x02


  int 0x13
  jc disk_error

  pop dx
  cmp dh, al
  jne disk_error
  ret
disk_error:
  mov bx, DISK_ERROR
  call print
  jmp $

switch_to_pm:
  cli

  lgdt [gdt_descriptor]

  mov eax, cr0
  or eax, 0x1
  mov cr0, eax

  jmp CODE_SEG:start_pm

load_kernel:
  mov bx, MSG_LOAD_KERNEL
  call print

  mov bx, KERNEL_OFFSET
  mov dh, 15
  mov dl, [BOOT_DRIVE]
  call disk_load

  ret

[bits 32]

start_pm:
  
  mov ax, DATA_SEG
  mov ds, ax
  mov ss, ax
  mov es, ax
  mov fs, ax
  mov gs, ax

  mov ebp, 0x90000
  mov esp, ebp
  
  call KERNEL_OFFSET

  jmp $

TEST_MSG: db "test", 0
MSG_LOAD_KERNEL: db "Loading kernel", 0
BOOT_DRIVE: db 0
HELLO_MSG: db "Hello world!", 0
DISK_ERROR: db "Disk read error!", 0

times 510-($-$$) db 0
; Magic bios numbers
dw 0xaa55
