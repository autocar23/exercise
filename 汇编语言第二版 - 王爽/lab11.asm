assume cs:codesg

datasg segment
	db "Beginner's All-purpose Symbolic Instruction Code.", 0
datasg ends

codesg segment
begin:
	mov ax, datasg
	mov ds, ax
	mov si, 0
	call letterc

	mov ax, 4c00h
	int 21h

letterc:
	push cx
	push si
	pushf
main:
	mov ch, 0
	mov cl, [si]
	jcxz return
	cmp cl, 61h
	jb next
	cmp cl, 7ah
	ja next
	and cl, 11011111b
	mov [si], cl
next:
	inc si
	jmp short main
return:
	popf
	pop si
	pop cx
	ret
codesg ends

end begin
