assume cs:code

code segment
start:
	mov ax, cs
	mov ds, ax
	mov si, offset do0
	mov ax, 020h
	mov es, ax
	mov di, 0
	mov cx, offset do0_end-offset do0 
	cld
	rep movsb

	mov ax, 0
	mov es, ax
	mov word ptr es:[0*4], 200h
	mov word ptr es:[0*4+2], 0

	mov bh, 1
	mov ax, 1000
	div bh

	mov ax, 4c00h
	int 21h

do0:jmp short do0start
	db 'overflow!'
do0start:
	mov ax, cs
	mov ds, ax
	mov si, 202h

	mov ax, 0B800h
	mov es, ax
	mov di, 12*160

	mov cx, 9
do0_loop0:
	mov al, [si]
	mov es:[di], al
	inc si
	add di, 2
	loop do0_loop0

	mov ax, 4c00h
	int 21h
do0_end:nop
code ends

end start
