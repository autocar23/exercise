assume cs:code

code segment
int7ch: 
	jmp short int7ch_main
;table dw sub1……中SUB1存放的应该是子程序的偏移地址，
;这个偏移地址是相对于中断程序入口的，而此时Sub1中存放的
;是相对于安装程序入口的地址。所以应该将被安装代码放到code段标号Start前边。
;前面assume cs:code ， 将本段中的数据标号的默认段地址设置为了cs
;所以在在安装程序中设置中断向量表时，应设：cs=200h，ip=0，而不是cs=0，ip=200h，如果是cs=0，
;则table里面的偏移地址cs:[偏移地址(sub1/sub2..)]会指向0:偏移地址，但是我们程序是安装在0200h:0处
;所以应设置cs=200h来让table里的定址表可以指向正确位置
	table dw sub1, sub2, sub3, sub4

int7ch_main:
	push ax
	push bx

	cmp ah, 3
	ja int7ch_ret

	mov bl, ah
	mov bh, 0
	add bx, bx
	call word ptr table[bx]

int7ch_ret:
	pop bx
	pop ax
	iret

sub1:
	push ax
	push bx
	push cx
	push es

	mov ax, 0b800h
	mov es, ax
	mov al, ' '
	mov ah, 0
	mov cx, 80*25
	mov bx, 0
  sub1_s:
	mov es:[bx], ax
	add bx, 2
	loop sub1_s

	pop es
	pop cx
	pop bx
	pop ax
	ret

sub2:
	push bx
	push cx
	push es

	mov bx, 0b800h
	mov es, bx
	mov cx, 80*25
	mov bx, 0
  sub2_s:
  	and es:[bx+1], 111111000b
  	or es:[bx+1], al
	add bx, 2
	loop sub2_s

	pop es
	pop cx
	pop bx
	ret

sub3:
	push bx
	push cx
	push es

	mov bx, 0b800h
	mov es, bx
	mov cx, 80*25
	mov bx, 0
  sub3_s:
  	and byte ptr es:[bx+1], 10001111b
  	or es:[bx+1], al
	add bx, 2
	loop sub3_s

	pop es
	pop cx
	pop bx
	ret

sub4:
	push ax
	push bx
	push cx
	push es

	mov ax, 0b800h
	mov es, ax
	mov cx, 80*24
	mov bx, 0
  sub4_s:
  	mov ax, es:[bx+80]
  	mov es:[bx], ax
  	add bx, 2
  	loop sub4_s

  	mov cx, 80
  	mov al, ' '
  sub4_s1:
  	mov es:[bx], al
  	add bx, 2
  	loop sub4_s1

  	pop es
  	pop cx
  	pop bx
  	pop ax
  	ret

int7ch_end:
	nop

start:	
	mov ax, cs ;设置ds:si
	mov ds, ax
	mov ax, offset int7ch
	mov si, ax

	mov ax, 0 ;设置es:di
	mov es, ax
	mov ax, 200h
	mov di, ax

	mov cx, offset int7ch_end-offset int7ch ;设置拷贝数据大小
	cld
	rep movsb ;开始拷贝中断历程到es:di
	
	;mov ax, 200h ;设置中断向量表
	cli
	;mov word ptr es:[7ch*4], ax
	mov word ptr es:[7ch*4], 0
	;mov ax, 0
	;mov word ptr es:[7ch*4+2], ax
	mov word ptr es:[7ch*4+2], 20h
	sti

	mov ah, 0
	int 7ch

	mov ax, 4c00h
	int 21h

code ends

end start