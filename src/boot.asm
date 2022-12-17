[bits 16]
  mov ax, 0x07c0
  mov ds, ax
  cld

  mov si, msg 
  call print_bios

hang: 
  jmp hang

msg: db 'Hello world', 13, 10, 0

print_bios:
  lodsb
  or al, al
  jz done
  mov ah, 0x0E
  mov bh, 0
  int 0x10
  jmp print_bios

done:
  ret

  times 510-($-$$) db 0
  db 0x55
  db 0xAA
