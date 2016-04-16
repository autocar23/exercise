assume cs:code
data segment
	db 'Welcome to masm!', 0
data ends

code segment
start:
	mov dh, 8
	mov dl, 3
	mov cl, 2
	mov ax, data
	mov ds, ax
	mov si, 0
	call show_str

	mov ax, 4c00h
	int 21h
	; function : show str at target position, the str must be end with 0
	; arguments : (dh) = line number, (dl) = row number, (cl) = color, ds:si point to str
	; return : none
show_str:
	push ax
	push bx
	push cx
	push dx
	push di
	push si
	push es

	mov bl, cl

	mov al, dh
	mov ah, 160
	mul ah
	mov di, ax
	mov dh, 0
	add di, dx
	add di, dx
	sub di, 2

do:	mov ax, 0B800H
	mov es, ax
	mov cl, [si]
	mov ch, 0
	jcxz ok
	mov es:[di], cl
	mov es:[di+1], bl
	inc si
	add di, 2
	jmp short do
	
ok:	pop es
	pop si
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	ret

code ends
end start
