assume cs:code

data segment
    db "welcome to masm!", 0
data ends

code segment
start:
    mov ax, cs
    mov ds, ax
    mov si, offset c
    mov ax, 0
    mov es, ax
    mov di, 200h
    mov cx, offset c_end-offset c
    cld
    rep movsb

    mov ax, 0
    mov es, ax
    mov word ptr es:[7ch*4], 200h
    mov word ptr es:[7ch*4+2], 0

    mov dh, 10
    mov dl, 10
    mov cl, 2
    mov ax, data
    mov ds, ax
    mov si, 0
    int 7ch

    mov ax, 4c00h
    int 21h

c:  push ax
    push es
    push si
    push di
    push dx

    mov ax, 0b800h
    mov es, ax
    mov al, 160
    mul dh
    mov dh, 0
    add ax, dx
    add ax, dx
    mov di, ax
c_main:
    mov al, ds:[si] 
    cmp al, 0
    je c_ok
    mov es:[di], al
    mov es:[di+1], cl
    inc si
    add di, 2
    jmp short c_main
c_ok:
    pop dx
    pop di
    pop si
    pop es
    pop ax
    iret
c_end:
    nop
    
code ends
end start
