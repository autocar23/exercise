assume cs:code

a segment
	db 1, 2, 3, 4, 5, 6, 7, 8
a ends

b segment
	db 1, 2, 3, 4, 5, 6, 7, 8
b ends

c segment
	db 0, 0, 0, 0, 0, 0, 0, 0
c ends

code segment
start:
	mov ax, a
	mov ds, ax

	mov bx, 0
	mov cx, 8
s:	mov dl, ds:[bx]
	add ds:[bx+20h],dl
	mov dl, ds:[bx+10h]
	add ds:[bx+20h], dl
	inc bx
	loop s
	
	mov ax, 4c00h
	int 21h
code ends

end start
