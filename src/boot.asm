; vim: ft=nasm
[bits 16]
  mov ax, 0x07c0
  mov ds, ax
  mov ss, ax
  mov sp, 0x9c00

  cld
  
  mov ax, 0xb800,
  mov es, ax

  mov si, msg 
  call sprint

  mov ax, 0xb800
  mov gs, ax
  mov bx, 0x0000
  mov ax, [gs:bx]
  mov word [reg16], ax
  call printreg16

hang: 
  jmp hang


dochar: call cprint
sprint: lodsb
  cmp al, 0
  jne dochar
  add byte [ypos], 1
  mov byte [xpos], 0
  ret

cprint: mov ah, 0x0F
  mov cx, ax
  movzx ax, byte [ypos]
  mov dx, 160
  mul dx
  movzx bx, byte [xpos]
  shl bx, 1

  mov di, 0
  add di, ax
  add di, bx

  mov ax, cx
  stosw
  add byte [xpos], 1 

  ret
printreg16:
  mov di, outstr16
  mov ax, [reg16]
  mov si, hexstr
  mov cx, 4

hexloop:
  rol ax, 4
  mov bx, ax
  and bx, 0x0f
  mov bl, [si + bx]
  mov [di], bl
  inc di
  dec cx
  jnz hexloop

xpos db 12
ypos db 12
hexstr db '0123456789ABCDEF'
outstr16 db '0000', 0
reg16 dw 0
msg: db 'Hello world', 0
times 510-($-$$) db 0
db 0x55
db 0xAA
