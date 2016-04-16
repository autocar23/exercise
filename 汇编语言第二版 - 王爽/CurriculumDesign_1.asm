assume cs:codesg
data segment
    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
	db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
	db '1993','1994','1995'
	
	dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000

    dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
    dw 11452,14430,15257,17800
data ends

table segment
	db 21 dup ('year summ ne ?? ')
table ends

codesg segment
start:
	call init
	mov ax, table
	mov ds, ax

	call screen_clean
	mov bl, 2
	mov cx, 21
	mov si, 0
main_loop_0:
	push cx
		mov dh, bl
		mov dl, 1
		mov cl, 2
		call show_str

		mov ax, ds:[5]
		mov dx, ds:[7]
		call dtoc
		mov dh, bl
		mov dl, 10
		mov cl, 2
		call show_str

		mov ax, ds:[0Ah]
		mov dx, 0
		call dtoc
		mov dh, bl
		mov dl, 20
		mov cl, 2
		call show_str

		mov ax, ds:[0Dh]
		mov dx, 0
		call dtoc
		mov dh, bl
		mov dl, 30
		mov cl, 2
		call show_str

		inc bl
		mov ax, ds
		inc ax
		mov ds, ax
	pop cx
	loop main_loop_0

	mov ax,4c00h
	int 21h

; name : screen_clean
; function: clean screen
; argument : none
; return : none
screen_clean:
	push ds
	push cx
	push bx
	push ax

	mov bx, 0B800H
	mov ds, bx
	mov cx, 2000
	mov bx, 0
	mov ax, 0
 screen_clean_loop:
	mov [bx], ax
	add bx, 2
	loop screen_clean_loop

	pop ax
	pop bx
	pop cx
	pop ds
	ret

; name : init
; function : init data
; arguments : none
; return : none
init:
	mov ax, data
	mov ds, ax
	mov ax, table
	mov es, ax
	
	mov bx, 0
	mov ax, 84
	mov si, ax
	add ax, 84
	mov di, ax
	mov bp, 0

	mov cx, 21
 init_s:
	mov ax, [bx]
	mov es:[bp], ax
	mov ax, [bx+2]
	mov es:[bp+2], ax
	mov al, 0
	mov es:[bp+4], al

	mov ax, [si]
	mov es:[bp+5], ax
	mov ax, [si+2]
	mov es:[bp+7], ax
	mov al, 0
	mov es:[bp+9], al

	mov ax, [di]
	mov es:[bp+10], ax
	mov al, 0
	mov byte ptr es:[bp+12], al

	mov dx, es:[bp+7]
	mov ax, es:[bp+5]
	div word ptr es:[bp+10]
	mov es:[bp+13], ax
	mov al, 0
	mov byte ptr es:[bp+15], al

	add bp, 10h
	add bx, 4
	add si, 4
	add di, 2

	loop init_s
	ret

; name : dtoc
; function : convert dword type data to decimal type ptr ended with 0
; arguments : (dx)(ax) = dword type data , ds:si point to the str
; return : none
dtoc:
	push ax
	push cx
	push dx
	push si
	push di

	mov di, si
 dtoc_do:
	mov cx, 10
	call divdw
	add cx, 30H
	push cx
	inc si
	mov cx, ax
	or cx, dx
	jcxz dtoc_step2
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
	pop ax
	ret

; name : show_str
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

end start
