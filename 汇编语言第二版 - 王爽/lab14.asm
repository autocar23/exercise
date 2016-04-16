assume cs:code

data segment
    db "yr/mo/da ho/mi/se", "$"
    db 9, 8, 7, 4, 2, 0
data ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov ax, 18
    mov si, ax
    mov ax, 0
    mov di, ax

    mov cx, 6
s:  mov al, [si]
    out 70h, al
    in al, 71h
    push cx
        mov cl, 4
        mov ah, al
        shr al, cl
        and ah, 00001111b
    pop cx
    add ah, 30h
    add al, 30h
    mov [di], ax
    inc si
    add di, 3
    loop s
    
    mov ah, 9
    mov dx, 0
    int 21h

    mov ax, 4c00h
    int 21h
code ends
end start
