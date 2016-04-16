assume cs:code

code segment
start:
	mov ax, 65535
	mov dx, 1
	mov cx, 12
	call divdw
	
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
codesg ends

code ends
end start
