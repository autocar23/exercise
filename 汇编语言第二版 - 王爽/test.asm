assume cs:code

code segment
start:
    mov ax, 0b800h
    mov es, ax
    mov ah, 'a'
s:  mov es:[160*12+40*2], ah
    call delay
    inc ah
    cmp ah, 'z'
    jna s
    mov ax, 4c00h
    int 21h

delay_1:
    push ax
    push dx
    mov dx, 10h
    mov ax, 0
delay_1_s1:
    sub ax, 1
    sbb dx, 0
    cmp ax, 0
    jne delay_1_s1
    cmp dx, 0
    jne delay_1_s1
    pop dx
    pop ax
    ret


delay:
    push ax

    mov al, 0
    out 70h, al
    in al, 71h
    and al, 00001111b
    mov ah, al
delay_s:
    mov al, 0
    out 70h, al
    in al, 71h
    and al, 00001111b
    cmp al, ah
    je delay_s

    pop ax
    ret

code ends
end start
