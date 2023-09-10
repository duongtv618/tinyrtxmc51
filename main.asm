;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _Timer0_ISR
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _curTask
	.globl _task2
	.globl _task1
	.globl __tick
	.globl _curSP
	.globl _delay_tick
	.globl _switch_to
	.globl _delay_us
	.globl _delay_ms
	.globl _task1_func
	.globl _task2_func
	.globl _timer0_init
	.globl _timer0_start
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_P1	=	0x0090
_SCON	=	0x0098
_SBUF	=	0x0099
_P2	=	0x00a0
_IE	=	0x00a8
_P3	=	0x00b0
_IP	=	0x00b8
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_IT0	=	0x0088
_IE0	=	0x0089
_IT1	=	0x008a
_IE1	=	0x008b
_TR0	=	0x008c
_TF0	=	0x008d
_TR1	=	0x008e
_TF1	=	0x008f
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_RI	=	0x0098
_TI	=	0x0099
_RB8	=	0x009a
_TB8	=	0x009b
_REN	=	0x009c
_SM2	=	0x009d
_SM1	=	0x009e
_SM0	=	0x009f
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_EX0	=	0x00a8
_ET0	=	0x00a9
_EX1	=	0x00aa
_ET1	=	0x00ab
_ES	=	0x00ac
_EA	=	0x00af
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_RXD	=	0x00b0
_TXD	=	0x00b1
_INT0	=	0x00b2
_INT1	=	0x00b3
_T0	=	0x00b4
_T1	=	0x00b5
_WR	=	0x00b6
_RD	=	0x00b7
_PX0	=	0x00b8
_PT0	=	0x00b9
_PX1	=	0x00ba
_PT1	=	0x00bb
_PS	=	0x00bc
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_curSP::
	.ds 1
__tick::
	.ds 2
_task1::
	.ds 3
_task2::
	.ds 3
_curTask::
	.ds 1
_main_a_65537_45	=	0x001f
_main_b_65537_45	=	0x0020
_main_c_65538_46	=	0x0055
_main_d_65538_46	=	0x0056
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	ljmp	_Timer0_ISR
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	main.c:6: unsigned char curSP = 0;
	mov	_curSP,#0x00
;	main.c:7: unsigned short _tick = 0;
	clr	a
	mov	__tick,a
	mov	(__tick + 1),a
;	main.c:88: } curTask = TASK1;
;	1-genFromRTrack replaced	mov	_curTask,#0x00
	mov	_curTask,a
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'Timer0_ISR'
;------------------------------------------------------------
;	main.c:72: void Timer0_ISR(void) __interrupt 1 __naked
;	-----------------------------------------
;	 function Timer0_ISR
;	-----------------------------------------
_Timer0_ISR:
;	naked function: no prologue.
;	main.c:74: TF0 = 0;
;	assignBit
	clr	_TF0
;	main.c:75: TH0 = 0xdb;
	mov	_TH0,#0xdb
;	main.c:76: TL0 = 0xff;
	mov	_TL0,#0xff
;	main.c:78: ++_tick;
	inc	__tick
	clr	a
	cjne	a,__tick,00103$
	inc	(__tick + 1)
00103$:
;	main.c:79: save_context();
	mov	_curSP,_SP
	push	ACC
	push	DPL
	push	DPH
	push	b
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	push	ar0
	push	ar1
	push	PSW
;	main.c:80: switch_to();
	lcall	_switch_to
;	main.c:81: restore_context();
	mov	_SP,_curSP
	pop	PSW
	pop	ar1
	pop	ar0
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	pop	b
	pop	DPH
	pop	DPL
	pop	ACC
	reti
;	main.c:82: }
;	naked function: no epilogue.
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;a                         Allocated with name '_main_a_65537_45'
;b                         Allocated with name '_main_b_65537_45'
;c                         Allocated with name '_main_c_65538_46'
;d                         Allocated with name '_main_d_65538_46'
;------------------------------------------------------------
;	main.c:90: void main()
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	main.c:93: EA = 1;
;	assignBit
	setb	_EA
;	main.c:94: ET0 = 1;
;	assignBit
	setb	_ET0
;	main.c:97: timer0_init();
	lcall	_timer0_init
;	main.c:98: timer0_start();
	lcall	_timer0_start
;	main.c:100: task1.sp = 0x1f;
	mov	(_task1 + 0x0002),#0x1f
;	main.c:101: task2.sp = 0x55;
	mov	(_task2 + 0x0002),#0x55
;	main.c:103: task1.pc = (unsigned short)(&task1_func);
	mov	r6,#_task1_func
	mov	r7,#(_task1_func >> 8)
	mov	(_task1 + 0),r6
	mov	(_task1 + 1),r7
;	main.c:104: task2.pc = (unsigned short)(&task2_func);
	mov	r4,#_task2_func
	mov	r5,#(_task2_func >> 8)
	mov	(_task2 + 0),r4
	mov	(_task2 + 1),r5
;	main.c:108: __data unsigned char __at(0x1f) a = (task1.pc) & 0xff;
	mov	_main_a_65537_45,r6
;	main.c:109: __data unsigned char __at(0x20) b = ((task1.pc) >> 8) & 0xff;
	mov	_main_b_65537_45,r7
;	main.c:111: task1.sp += 14;
	mov	r7,(_task1 + 0x0002)
	mov	a,#0x0e
	add	a,r7
	mov	(_task1 + 0x0002),a
;	main.c:115: __data unsigned char __at(0x55) c = (task2.pc) & 0xff;
	mov	_main_c_65538_46,r4
;	main.c:116: __data unsigned char __at(0x56) d = ((task2.pc) >> 8) & 0xff;
	mov	_main_d_65538_46,r5
;	main.c:118: task2.sp += 14;
	mov	r7,(_task2 + 0x0002)
	mov	a,#0x0e
	add	a,r7
	mov	(_task2 + 0x0002),a
;	main.c:119: curSP = task1.sp;
	mov	_curSP,(_task1 + 0x0002)
;	main.c:122: restore_context();
	mov	_SP,_curSP
	pop	PSW
	pop	ar1
	pop	ar0
	pop	ar7
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
	pop	b
	pop	DPH
	pop	DPL
	pop	ACC
	reti
;	main.c:124: while (1)
00102$:
;	main.c:126: }
	sjmp	00102$
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_tick'
;------------------------------------------------------------
;tick                      Allocated to registers r6 r7 
;------------------------------------------------------------
;	main.c:128: void delay_tick(unsigned short tick)
;	-----------------------------------------
;	 function delay_tick
;	-----------------------------------------
_delay_tick:
	mov	r6,dpl
	mov	r7,dph
;	main.c:130: tick += _tick;
	mov	a,__tick
	add	a,r6
	mov	r6,a
	mov	a,(__tick + 1)
	addc	a,r7
	mov	r7,a
;	main.c:131: while (_tick < tick)
00101$:
	clr	c
	mov	a,__tick
	subb	a,r6
	mov	a,(__tick + 1)
	subb	a,r7
	jc	00101$
;	main.c:133: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'switch_to'
;------------------------------------------------------------
;	main.c:135: void switch_to(void)
;	-----------------------------------------
;	 function switch_to
;	-----------------------------------------
_switch_to:
;	main.c:137: if (curTask == TASK1)
	mov	a,_curTask
	jnz	00102$
;	main.c:139: task1.sp = curSP;
	mov	(_task1 + 0x0002),_curSP
;	main.c:140: curTask = TASK2;
	mov	_curTask,#0x01
;	main.c:141: curSP = task2.sp;
	mov	_curSP,(_task2 + 0x0002)
	ret
00102$:
;	main.c:145: task2.sp = curSP;
	mov	(_task2 + 0x0002),_curSP
;	main.c:146: curTask = TASK1;
	mov	_curTask,#0x00
;	main.c:147: curSP = task1.sp;
	mov	_curSP,(_task1 + 0x0002)
;	main.c:149: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_us'
;------------------------------------------------------------
;us                        Allocated to registers 
;------------------------------------------------------------
;	main.c:151: void delay_us(unsigned short us)
;	-----------------------------------------
;	 function delay_us
;	-----------------------------------------
_delay_us:
	mov	r6,dpl
	mov	r7,dph
;	main.c:153: while (--us)
00101$:
	dec	r6
	cjne	r6,#0xff,00111$
	dec	r7
00111$:
	mov	a,r6
	orl	a,r7
	jnz	00101$
;	main.c:155: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay_ms'
;------------------------------------------------------------
;ms                        Allocated to registers 
;------------------------------------------------------------
;	main.c:156: void delay_ms(unsigned short ms)
;	-----------------------------------------
;	 function delay_ms
;	-----------------------------------------
_delay_ms:
	mov	r6,dpl
	mov	r7,dph
;	main.c:158: while (--ms)
00101$:
	dec	r6
	cjne	r6,#0xff,00115$
	dec	r7
00115$:
	mov	a,r6
	orl	a,r7
	jz	00104$
;	main.c:159: delay_us(1000);
	mov	dptr,#0x03e8
	push	ar7
	push	ar6
	lcall	_delay_us
	pop	ar6
	pop	ar7
	sjmp	00101$
00104$:
;	main.c:160: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'task1_func'
;------------------------------------------------------------
;	main.c:162: void task1_func(void)
;	-----------------------------------------
;	 function task1_func
;	-----------------------------------------
_task1_func:
;	main.c:164: while (1)
00102$:
;	main.c:166: P1_1 = !P1_1;
	cpl	_P1_1
;	main.c:167: delay_tick(100);
	mov	dptr,#0x0064
	lcall	_delay_tick
;	main.c:169: }
	sjmp	00102$
;------------------------------------------------------------
;Allocation info for local variables in function 'task2_func'
;------------------------------------------------------------
;	main.c:171: void task2_func(void)
;	-----------------------------------------
;	 function task2_func
;	-----------------------------------------
_task2_func:
;	main.c:173: while (1)
00102$:
;	main.c:175: P2_1 = !P2_1;
	cpl	_P2_1
;	main.c:176: delay_tick(200);
	mov	dptr,#0x00c8
	lcall	_delay_tick
;	main.c:178: }
	sjmp	00102$
;------------------------------------------------------------
;Allocation info for local variables in function 'timer0_init'
;------------------------------------------------------------
;	main.c:180: void timer0_init(void)
;	-----------------------------------------
;	 function timer0_init
;	-----------------------------------------
_timer0_init:
;	main.c:182: TMOD += 0x01;
	mov	a,_TMOD
	inc	a
	mov	_TMOD,a
;	main.c:183: TH0 = 0xdb;
	mov	_TH0,#0xdb
;	main.c:184: TL0 = 0xff;
	mov	_TL0,#0xff
;	main.c:185: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'timer0_start'
;------------------------------------------------------------
;	main.c:187: void timer0_start(void)
;	-----------------------------------------
;	 function timer0_start
;	-----------------------------------------
_timer0_start:
;	main.c:189: TR0 = 1;
;	assignBit
	setb	_TR0
;	main.c:190: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
