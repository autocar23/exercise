assume cs:code

data segment
	db 10 dup (0)
data ends

code segment
start:
	mov ax, 12666
	mov bx, data
	mov ds, bx
	mov si, 0
	call dtoc

	mov dh, 8
	mov dl, 3
	mov cl, 2
	call show_str

	mov ax, 4c00h
	int 21h
	
	; name : dtoc
	; function : convert word type data to decimal type ptr ended with 0
	; arguments : (ax) = word type data , ds:si point to the str
	; return : none
dtoc:
	push ax
	push bx
	push cx
	push dx
	push si
	push di

	mov dx, 0
	mov bx, 10
	mov di, si
dtoc_do:
	div bx
	mov cx, dx
	jcxz dtoc_step2
	add cx, 30H
	;mov byte ptr [si], cl
	push cx
	inc si
	mov dx, 0
	jmp short dtoc_do

dtoc_step2:
	mov cx, si
	sub cx, di
	jcxz dtoc_ok
	pop cx
	mov [di], cl
	inc di
	jmp short dtoc_step2

dtoc_ok:
	mov cl, 0
	mov [si], cl
	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret


	; function : show str at target position, the str must be end with 0
	; arguments : (dh) = line number, (dl) = row number, (cl) = color, ds:si point to the str
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

showstr_do:
	mov ax, 0B800H
	mov es, ax
	mov cl, [si]
	mov ch, 0
	jcxz showstr_ok
	mov es:[di], cl
	mov es:[di+1], bl
	inc si
	add di, 2
	jmp short showstr_do
	
showstr_ok:
	pop es
	pop si
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	ret

code ends
end start
