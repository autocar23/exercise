assume cs:code

code segment
	mov cx, 236h
	mov ax, 0h
s:	add ax, 123h
	loop s
	
	mov bx, ax
	mov ax, 4c00h
	int 21h
code ends
end
