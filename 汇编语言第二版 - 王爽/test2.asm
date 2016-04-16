assume cs:code

code segment
start:
	mov dx, 1
	mov ax, 12666
s0:	mov cx, 10
	call divdw
	mov cx, ax
	jcxz s
	jmp short s0
	

s:
	mov ax, 4c00h
	int 21h


; name : divdw
; function: divition whitout overflow, 
; numerator : dword, denominator : word, result : dword
; arguments : (dx)(ax) / (cx)
; return : result : (dx)(ax), remainder : (cx)
divdw:
	push bx
	push ax
	mov ax, dx
	mov dx, 0
	div cx
	mov bx, ax

	pop ax
	div cx
	mov cx, dx
	mov dx, bx
	pop bx
	ret

code ends

end start