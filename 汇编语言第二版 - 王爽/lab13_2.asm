assume cs:code

code segment
start:
    mov ax, cs
    mov ds, ax
    mov si, offset c
    mov ax, 0
    mov es, ax
    mov di, 200h
    mov cx, offset c_end-offset c
    rep movsb

    mov ax, 0
    mov es, ax
    mov word ptr es:[7ch*4], 200h
    mov word ptr es:[7ch*4+2], 0

    mov ax, 0b800h
    mov es, ax
    mov di, 160*21
    mov bx, offset s-offset se
    mov cx, 80
s:  mov byte ptr es:[di], '!'
    add di, 2
    int 7ch
se:nop
    mov ax, 4c00h
    int 21h

c:  push ax
    push bp

    mov ax, sp
    mov bp, ax
    dec cx
    jcxz c_ok
    add [bp+4], bx
c_ok:
    pop bp
    pop ax
    iret
c_end:
    nop
code ends
end start
