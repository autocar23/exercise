assume cs:code, ds:data, ss:stack

data segment
	db 'welcome to masm!'
	db 00000010B
	db 00100100B
	db 01110001B
data ends

stack segment
	db 16 dup (0)
stack ends

code segment
start:
	mov ax, data
	mov ds, ax
	mov ax, stack
	mov ss, ax
	mov sp, 16
	mov ax, 0b800h
	mov es, ax
	
	mov cx, 2000
	mov ax, 0
	mov bx, 0
q:	mov es:[bx], ax
	add bx, 2
	loop q

	mov bx, 0
	mov si, 0
	mov di, 0
	
	mov bx, 1760
	mov di, 64
	mov cx, 3
s:	push cx
		mov cx, 16
	s0:	mov al, [si]
		mov es:[bx+di], al
		inc si
		add di, 2
		loop s0
	pop cx
	mov si, 0
	mov di, 64
	add bx, 160
	loop s
	
	mov si, 0
	mov di, 0
	mov bx, 0
	mov ax, ds
	inc ax
	mov ds, ax
	
	mov bx, 1760
	mov di, 65
	mov cx, 3
t:	push cx
		mov cx, 16
		mov al, [si]
	t0:	mov es:[bx+di], al
		add di, 2
		loop t0
	pop cx
	inc si
	mov di ,65
	add bx, 160
	loop t

	mov ax, 4c00h
	int 21h
code ends

end start
