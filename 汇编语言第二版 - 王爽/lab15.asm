assume cs:code

code segment
start:
    mov ax, cs
    mov ds, ax
    mov si, offset int9

    mov ax, 0
    mov es, ax
    mov di, 204h
    
    mov cx, offset int9_end-offset int9
    cld
    rep movsb

    mov ax, es:[9*4]
    mov es:[200h], ax
    mov ax, es:[9*4+2]
    mov es:[202h], ax
    
    sti
    mov word ptr es:[9*4], 200h
    mov word ptr es:[9*4+2], 0
    cli

    mov ax, 4c00h
    int 21h

int9:
    push ax
    push bx
    push cx
    push ds

    in al, 60h
    
    pushf
    call dword ptr cs:[200h]

    cmp al, 1Eh+80h
    jne int9_ret

    mov ax, 0b800h
    mov ds, ax
    mov al, 'A'
    mov bx, 0
    mov cx, 80*25
int9_s:
    mov ds:[bx], al
    add bx, 2
    loop int9_s

int9_ret:
    pop ds
    pop cx
    pop bx
    pop ax
    iret 
int9_end:
    nop

code ends
end start
