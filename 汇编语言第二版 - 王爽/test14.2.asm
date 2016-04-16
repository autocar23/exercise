assume cs:code

code segment
    mov ax, 10
    
    shl ax, 1
    push ax
    mov cl, 2
    shl ax, cl
    mov bp, sp
    add ax, [bp]

    mov ax, 4c00h
    int 21h
code ends
end
