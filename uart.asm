org	0h
ljmp	main

org 	800H
main:	mov scon, #50h
		mov	tmod, #20h
		mov th1, #-3
		mov pcon, #80h
		setb tr1

		mov a, #30h
		call write
loop:
read:	jnb ri, read
		clr ri
		mov a, sbuf
		call write
		sjmp read
write:
		mov sbuf,a
waitti:	jnb ti, waitti
		clr ti;end transfer
		ret