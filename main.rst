                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _Timer0_ISR
                                     13 	.globl _CY
                                     14 	.globl _AC
                                     15 	.globl _F0
                                     16 	.globl _RS1
                                     17 	.globl _RS0
                                     18 	.globl _OV
                                     19 	.globl _F1
                                     20 	.globl _P
                                     21 	.globl _PS
                                     22 	.globl _PT1
                                     23 	.globl _PX1
                                     24 	.globl _PT0
                                     25 	.globl _PX0
                                     26 	.globl _RD
                                     27 	.globl _WR
                                     28 	.globl _T1
                                     29 	.globl _T0
                                     30 	.globl _INT1
                                     31 	.globl _INT0
                                     32 	.globl _TXD
                                     33 	.globl _RXD
                                     34 	.globl _P3_7
                                     35 	.globl _P3_6
                                     36 	.globl _P3_5
                                     37 	.globl _P3_4
                                     38 	.globl _P3_3
                                     39 	.globl _P3_2
                                     40 	.globl _P3_1
                                     41 	.globl _P3_0
                                     42 	.globl _EA
                                     43 	.globl _ES
                                     44 	.globl _ET1
                                     45 	.globl _EX1
                                     46 	.globl _ET0
                                     47 	.globl _EX0
                                     48 	.globl _P2_7
                                     49 	.globl _P2_6
                                     50 	.globl _P2_5
                                     51 	.globl _P2_4
                                     52 	.globl _P2_3
                                     53 	.globl _P2_2
                                     54 	.globl _P2_1
                                     55 	.globl _P2_0
                                     56 	.globl _SM0
                                     57 	.globl _SM1
                                     58 	.globl _SM2
                                     59 	.globl _REN
                                     60 	.globl _TB8
                                     61 	.globl _RB8
                                     62 	.globl _TI
                                     63 	.globl _RI
                                     64 	.globl _P1_7
                                     65 	.globl _P1_6
                                     66 	.globl _P1_5
                                     67 	.globl _P1_4
                                     68 	.globl _P1_3
                                     69 	.globl _P1_2
                                     70 	.globl _P1_1
                                     71 	.globl _P1_0
                                     72 	.globl _TF1
                                     73 	.globl _TR1
                                     74 	.globl _TF0
                                     75 	.globl _TR0
                                     76 	.globl _IE1
                                     77 	.globl _IT1
                                     78 	.globl _IE0
                                     79 	.globl _IT0
                                     80 	.globl _P0_7
                                     81 	.globl _P0_6
                                     82 	.globl _P0_5
                                     83 	.globl _P0_4
                                     84 	.globl _P0_3
                                     85 	.globl _P0_2
                                     86 	.globl _P0_1
                                     87 	.globl _P0_0
                                     88 	.globl _B
                                     89 	.globl _ACC
                                     90 	.globl _PSW
                                     91 	.globl _IP
                                     92 	.globl _P3
                                     93 	.globl _IE
                                     94 	.globl _P2
                                     95 	.globl _SBUF
                                     96 	.globl _SCON
                                     97 	.globl _P1
                                     98 	.globl _TH1
                                     99 	.globl _TH0
                                    100 	.globl _TL1
                                    101 	.globl _TL0
                                    102 	.globl _TMOD
                                    103 	.globl _TCON
                                    104 	.globl _PCON
                                    105 	.globl _DPH
                                    106 	.globl _DPL
                                    107 	.globl _SP
                                    108 	.globl _P0
                                    109 	.globl _curTask
                                    110 	.globl _task2
                                    111 	.globl _task1
                                    112 	.globl __tick
                                    113 	.globl _curSP
                                    114 	.globl _delay_tick
                                    115 	.globl _switch_to
                                    116 	.globl _delay_us
                                    117 	.globl _delay_ms
                                    118 	.globl _task1_func
                                    119 	.globl _task2_func
                                    120 	.globl _timer0_init
                                    121 	.globl _timer0_start
                                    122 ;--------------------------------------------------------
                                    123 ; special function registers
                                    124 ;--------------------------------------------------------
                                    125 	.area RSEG    (ABS,DATA)
      000000                        126 	.org 0x0000
                           000080   127 _P0	=	0x0080
                           000081   128 _SP	=	0x0081
                           000082   129 _DPL	=	0x0082
                           000083   130 _DPH	=	0x0083
                           000087   131 _PCON	=	0x0087
                           000088   132 _TCON	=	0x0088
                           000089   133 _TMOD	=	0x0089
                           00008A   134 _TL0	=	0x008a
                           00008B   135 _TL1	=	0x008b
                           00008C   136 _TH0	=	0x008c
                           00008D   137 _TH1	=	0x008d
                           000090   138 _P1	=	0x0090
                           000098   139 _SCON	=	0x0098
                           000099   140 _SBUF	=	0x0099
                           0000A0   141 _P2	=	0x00a0
                           0000A8   142 _IE	=	0x00a8
                           0000B0   143 _P3	=	0x00b0
                           0000B8   144 _IP	=	0x00b8
                           0000D0   145 _PSW	=	0x00d0
                           0000E0   146 _ACC	=	0x00e0
                           0000F0   147 _B	=	0x00f0
                                    148 ;--------------------------------------------------------
                                    149 ; special function bits
                                    150 ;--------------------------------------------------------
                                    151 	.area RSEG    (ABS,DATA)
      000000                        152 	.org 0x0000
                           000080   153 _P0_0	=	0x0080
                           000081   154 _P0_1	=	0x0081
                           000082   155 _P0_2	=	0x0082
                           000083   156 _P0_3	=	0x0083
                           000084   157 _P0_4	=	0x0084
                           000085   158 _P0_5	=	0x0085
                           000086   159 _P0_6	=	0x0086
                           000087   160 _P0_7	=	0x0087
                           000088   161 _IT0	=	0x0088
                           000089   162 _IE0	=	0x0089
                           00008A   163 _IT1	=	0x008a
                           00008B   164 _IE1	=	0x008b
                           00008C   165 _TR0	=	0x008c
                           00008D   166 _TF0	=	0x008d
                           00008E   167 _TR1	=	0x008e
                           00008F   168 _TF1	=	0x008f
                           000090   169 _P1_0	=	0x0090
                           000091   170 _P1_1	=	0x0091
                           000092   171 _P1_2	=	0x0092
                           000093   172 _P1_3	=	0x0093
                           000094   173 _P1_4	=	0x0094
                           000095   174 _P1_5	=	0x0095
                           000096   175 _P1_6	=	0x0096
                           000097   176 _P1_7	=	0x0097
                           000098   177 _RI	=	0x0098
                           000099   178 _TI	=	0x0099
                           00009A   179 _RB8	=	0x009a
                           00009B   180 _TB8	=	0x009b
                           00009C   181 _REN	=	0x009c
                           00009D   182 _SM2	=	0x009d
                           00009E   183 _SM1	=	0x009e
                           00009F   184 _SM0	=	0x009f
                           0000A0   185 _P2_0	=	0x00a0
                           0000A1   186 _P2_1	=	0x00a1
                           0000A2   187 _P2_2	=	0x00a2
                           0000A3   188 _P2_3	=	0x00a3
                           0000A4   189 _P2_4	=	0x00a4
                           0000A5   190 _P2_5	=	0x00a5
                           0000A6   191 _P2_6	=	0x00a6
                           0000A7   192 _P2_7	=	0x00a7
                           0000A8   193 _EX0	=	0x00a8
                           0000A9   194 _ET0	=	0x00a9
                           0000AA   195 _EX1	=	0x00aa
                           0000AB   196 _ET1	=	0x00ab
                           0000AC   197 _ES	=	0x00ac
                           0000AF   198 _EA	=	0x00af
                           0000B0   199 _P3_0	=	0x00b0
                           0000B1   200 _P3_1	=	0x00b1
                           0000B2   201 _P3_2	=	0x00b2
                           0000B3   202 _P3_3	=	0x00b3
                           0000B4   203 _P3_4	=	0x00b4
                           0000B5   204 _P3_5	=	0x00b5
                           0000B6   205 _P3_6	=	0x00b6
                           0000B7   206 _P3_7	=	0x00b7
                           0000B0   207 _RXD	=	0x00b0
                           0000B1   208 _TXD	=	0x00b1
                           0000B2   209 _INT0	=	0x00b2
                           0000B3   210 _INT1	=	0x00b3
                           0000B4   211 _T0	=	0x00b4
                           0000B5   212 _T1	=	0x00b5
                           0000B6   213 _WR	=	0x00b6
                           0000B7   214 _RD	=	0x00b7
                           0000B8   215 _PX0	=	0x00b8
                           0000B9   216 _PT0	=	0x00b9
                           0000BA   217 _PX1	=	0x00ba
                           0000BB   218 _PT1	=	0x00bb
                           0000BC   219 _PS	=	0x00bc
                           0000D0   220 _P	=	0x00d0
                           0000D1   221 _F1	=	0x00d1
                           0000D2   222 _OV	=	0x00d2
                           0000D3   223 _RS0	=	0x00d3
                           0000D4   224 _RS1	=	0x00d4
                           0000D5   225 _F0	=	0x00d5
                           0000D6   226 _AC	=	0x00d6
                           0000D7   227 _CY	=	0x00d7
                                    228 ;--------------------------------------------------------
                                    229 ; overlayable register banks
                                    230 ;--------------------------------------------------------
                                    231 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        232 	.ds 8
                                    233 ;--------------------------------------------------------
                                    234 ; internal ram data
                                    235 ;--------------------------------------------------------
                                    236 	.area DSEG    (DATA)
      000008                        237 _curSP::
      000008                        238 	.ds 1
      000009                        239 __tick::
      000009                        240 	.ds 2
      00000B                        241 _task1::
      00000B                        242 	.ds 3
      00000E                        243 _task2::
      00000E                        244 	.ds 3
      000011                        245 _curTask::
      000011                        246 	.ds 1
                           00001F   247 _main_a_65537_45	=	0x001f
                           000020   248 _main_b_65537_45	=	0x0020
                           000055   249 _main_c_65538_46	=	0x0055
                           000056   250 _main_d_65538_46	=	0x0056
                                    251 ;--------------------------------------------------------
                                    252 ; overlayable items in internal ram
                                    253 ;--------------------------------------------------------
                                    254 	.area	OSEG    (OVR,DATA)
                                    255 	.area	OSEG    (OVR,DATA)
                                    256 ;--------------------------------------------------------
                                    257 ; Stack segment in internal ram
                                    258 ;--------------------------------------------------------
                                    259 	.area	SSEG
      000012                        260 __start__stack:
      000012                        261 	.ds	1
                                    262 
                                    263 ;--------------------------------------------------------
                                    264 ; indirectly addressable internal ram data
                                    265 ;--------------------------------------------------------
                                    266 	.area ISEG    (DATA)
                                    267 ;--------------------------------------------------------
                                    268 ; absolute internal ram data
                                    269 ;--------------------------------------------------------
                                    270 	.area IABS    (ABS,DATA)
                                    271 	.area IABS    (ABS,DATA)
                                    272 ;--------------------------------------------------------
                                    273 ; bit data
                                    274 ;--------------------------------------------------------
                                    275 	.area BSEG    (BIT)
                                    276 ;--------------------------------------------------------
                                    277 ; paged external ram data
                                    278 ;--------------------------------------------------------
                                    279 	.area PSEG    (PAG,XDATA)
                                    280 ;--------------------------------------------------------
                                    281 ; external ram data
                                    282 ;--------------------------------------------------------
                                    283 	.area XSEG    (XDATA)
                                    284 ;--------------------------------------------------------
                                    285 ; absolute external ram data
                                    286 ;--------------------------------------------------------
                                    287 	.area XABS    (ABS,XDATA)
                                    288 ;--------------------------------------------------------
                                    289 ; external initialized ram data
                                    290 ;--------------------------------------------------------
                                    291 	.area XISEG   (XDATA)
                                    292 	.area HOME    (CODE)
                                    293 	.area GSINIT0 (CODE)
                                    294 	.area GSINIT1 (CODE)
                                    295 	.area GSINIT2 (CODE)
                                    296 	.area GSINIT3 (CODE)
                                    297 	.area GSINIT4 (CODE)
                                    298 	.area GSINIT5 (CODE)
                                    299 	.area GSINIT  (CODE)
                                    300 	.area GSFINAL (CODE)
                                    301 	.area CSEG    (CODE)
                                    302 ;--------------------------------------------------------
                                    303 ; interrupt vector
                                    304 ;--------------------------------------------------------
                                    305 	.area HOME    (CODE)
      000000                        306 __interrupt_vect:
      000000 02 00 11         [24]  307 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  308 	reti
      000004                        309 	.ds	7
      00000B 02 00 77         [24]  310 	ljmp	_Timer0_ISR
                                    311 ;--------------------------------------------------------
                                    312 ; global & static initialisations
                                    313 ;--------------------------------------------------------
                                    314 	.area HOME    (CODE)
                                    315 	.area GSINIT  (CODE)
                                    316 	.area GSFINAL (CODE)
                                    317 	.area GSINIT  (CODE)
                                    318 	.globl __sdcc_gsinit_startup
                                    319 	.globl __sdcc_program_startup
                                    320 	.globl __start__stack
                                    321 	.globl __mcs51_genXINIT
                                    322 	.globl __mcs51_genXRAMCLEAR
                                    323 	.globl __mcs51_genRAMCLEAR
                                    324 ;	main.c:6: unsigned char curSP = 0;
      00006A 75 08 00         [24]  325 	mov	_curSP,#0x00
                                    326 ;	main.c:7: unsigned short _tick = 0;
      00006D E4               [12]  327 	clr	a
      00006E F5 09            [12]  328 	mov	__tick,a
      000070 F5 0A            [12]  329 	mov	(__tick + 1),a
                                    330 ;	main.c:88: } curTask = TASK1;
                                    331 ;	1-genFromRTrack replaced	mov	_curTask,#0x00
      000072 F5 11            [12]  332 	mov	_curTask,a
                                    333 	.area GSFINAL (CODE)
      000074 02 00 0E         [24]  334 	ljmp	__sdcc_program_startup
                                    335 ;--------------------------------------------------------
                                    336 ; Home
                                    337 ;--------------------------------------------------------
                                    338 	.area HOME    (CODE)
                                    339 	.area HOME    (CODE)
      00000E                        340 __sdcc_program_startup:
      00000E 02 00 C5         [24]  341 	ljmp	_main
                                    342 ;	return from main will return to caller
                                    343 ;--------------------------------------------------------
                                    344 ; code
                                    345 ;--------------------------------------------------------
                                    346 	.area CSEG    (CODE)
                                    347 ;------------------------------------------------------------
                                    348 ;Allocation info for local variables in function 'Timer0_ISR'
                                    349 ;------------------------------------------------------------
                                    350 ;	main.c:72: void Timer0_ISR(void) __interrupt 1 __naked
                                    351 ;	-----------------------------------------
                                    352 ;	 function Timer0_ISR
                                    353 ;	-----------------------------------------
      000077                        354 _Timer0_ISR:
                                    355 ;	naked function: no prologue.
                                    356 ;	main.c:74: TF0 = 0;
                                    357 ;	assignBit
      000077 C2 8D            [12]  358 	clr	_TF0
                                    359 ;	main.c:75: TH0 = 0xdb;
      000079 75 8C DB         [24]  360 	mov	_TH0,#0xdb
                                    361 ;	main.c:76: TL0 = 0xff;
      00007C 75 8A FF         [24]  362 	mov	_TL0,#0xff
                                    363 ;	main.c:78: ++_tick;
      00007F 05 09            [12]  364 	inc	__tick
      000081 E4               [12]  365 	clr	a
      000082 B5 09 02         [24]  366 	cjne	a,__tick,00103$
      000085 05 0A            [12]  367 	inc	(__tick + 1)
      000087                        368 00103$:
                                    369 ;	main.c:79: save_context();
      000087 85 81 08         [24]  370 	mov	_curSP,_SP
      00008A C0 E0            [24]  371 	push	ACC
      00008C C0 82            [24]  372 	push	DPL
      00008E C0 83            [24]  373 	push	DPH
      000090 C0 F0            [24]  374 	push	b
      000092 C0 02            [24]  375 	push	ar2
      000094 C0 03            [24]  376 	push	ar3
      000096 C0 04            [24]  377 	push	ar4
      000098 C0 05            [24]  378 	push	ar5
      00009A C0 06            [24]  379 	push	ar6
      00009C C0 07            [24]  380 	push	ar7
      00009E C0 00            [24]  381 	push	ar0
      0000A0 C0 01            [24]  382 	push	ar1
      0000A2 C0 D0            [24]  383 	push	PSW
                                    384 ;	main.c:80: switch_to();
      0000A4 12 01 34         [24]  385 	lcall	_switch_to
                                    386 ;	main.c:81: restore_context();
      0000A7 85 08 81         [24]  387 	mov	_SP,_curSP
      0000AA D0 D0            [24]  388 	pop	PSW
      0000AC D0 01            [24]  389 	pop	ar1
      0000AE D0 00            [24]  390 	pop	ar0
      0000B0 D0 07            [24]  391 	pop	ar7
      0000B2 D0 06            [24]  392 	pop	ar6
      0000B4 D0 05            [24]  393 	pop	ar5
      0000B6 D0 04            [24]  394 	pop	ar4
      0000B8 D0 03            [24]  395 	pop	ar3
      0000BA D0 02            [24]  396 	pop	ar2
      0000BC D0 F0            [24]  397 	pop	b
      0000BE D0 83            [24]  398 	pop	DPH
      0000C0 D0 82            [24]  399 	pop	DPL
      0000C2 D0 E0            [24]  400 	pop	ACC
      0000C4 32               [24]  401 	reti
                                    402 ;	main.c:82: }
                                    403 ;	naked function: no epilogue.
                                    404 ;------------------------------------------------------------
                                    405 ;Allocation info for local variables in function 'main'
                                    406 ;------------------------------------------------------------
                                    407 ;a                         Allocated with name '_main_a_65537_45'
                                    408 ;b                         Allocated with name '_main_b_65537_45'
                                    409 ;c                         Allocated with name '_main_c_65538_46'
                                    410 ;d                         Allocated with name '_main_d_65538_46'
                                    411 ;------------------------------------------------------------
                                    412 ;	main.c:90: void main()
                                    413 ;	-----------------------------------------
                                    414 ;	 function main
                                    415 ;	-----------------------------------------
      0000C5                        416 _main:
                           000007   417 	ar7 = 0x07
                           000006   418 	ar6 = 0x06
                           000005   419 	ar5 = 0x05
                           000004   420 	ar4 = 0x04
                           000003   421 	ar3 = 0x03
                           000002   422 	ar2 = 0x02
                           000001   423 	ar1 = 0x01
                           000000   424 	ar0 = 0x00
                                    425 ;	main.c:93: EA = 1;
                                    426 ;	assignBit
      0000C5 D2 AF            [12]  427 	setb	_EA
                                    428 ;	main.c:94: ET0 = 1;
                                    429 ;	assignBit
      0000C7 D2 A9            [12]  430 	setb	_ET0
                                    431 ;	main.c:97: timer0_init();
      0000C9 12 01 8C         [24]  432 	lcall	_timer0_init
                                    433 ;	main.c:98: timer0_start();
      0000CC 12 01 98         [24]  434 	lcall	_timer0_start
                                    435 ;	main.c:100: task1.sp = 0x1f;
      0000CF 75 0D 1F         [24]  436 	mov	(_task1 + 0x0002),#0x1f
                                    437 ;	main.c:101: task2.sp = 0x55;
      0000D2 75 10 55         [24]  438 	mov	(_task2 + 0x0002),#0x55
                                    439 ;	main.c:103: task1.pc = (unsigned short)(&task1_func);
      0000D5 7E 78            [12]  440 	mov	r6,#_task1_func
      0000D7 7F 01            [12]  441 	mov	r7,#(_task1_func >> 8)
      0000D9 8E 0B            [24]  442 	mov	(_task1 + 0),r6
      0000DB 8F 0C            [24]  443 	mov	(_task1 + 1),r7
                                    444 ;	main.c:104: task2.pc = (unsigned short)(&task2_func);
      0000DD 7C 82            [12]  445 	mov	r4,#_task2_func
      0000DF 7D 01            [12]  446 	mov	r5,#(_task2_func >> 8)
      0000E1 8C 0E            [24]  447 	mov	(_task2 + 0),r4
      0000E3 8D 0F            [24]  448 	mov	(_task2 + 1),r5
                                    449 ;	main.c:108: __data unsigned char __at(0x1f) a = (task1.pc) & 0xff;
      0000E5 8E 1F            [24]  450 	mov	_main_a_65537_45,r6
                                    451 ;	main.c:109: __data unsigned char __at(0x20) b = ((task1.pc) >> 8) & 0xff;
      0000E7 8F 20            [24]  452 	mov	_main_b_65537_45,r7
                                    453 ;	main.c:111: task1.sp += 14;
      0000E9 AF 0D            [24]  454 	mov	r7,(_task1 + 0x0002)
      0000EB 74 0E            [12]  455 	mov	a,#0x0e
      0000ED 2F               [12]  456 	add	a,r7
      0000EE F5 0D            [12]  457 	mov	(_task1 + 0x0002),a
                                    458 ;	main.c:115: __data unsigned char __at(0x55) c = (task2.pc) & 0xff;
      0000F0 8C 55            [24]  459 	mov	_main_c_65538_46,r4
                                    460 ;	main.c:116: __data unsigned char __at(0x56) d = ((task2.pc) >> 8) & 0xff;
      0000F2 8D 56            [24]  461 	mov	_main_d_65538_46,r5
                                    462 ;	main.c:118: task2.sp += 14;
      0000F4 AF 10            [24]  463 	mov	r7,(_task2 + 0x0002)
      0000F6 74 0E            [12]  464 	mov	a,#0x0e
      0000F8 2F               [12]  465 	add	a,r7
      0000F9 F5 10            [12]  466 	mov	(_task2 + 0x0002),a
                                    467 ;	main.c:119: curSP = task1.sp;
      0000FB 85 0D 08         [24]  468 	mov	_curSP,(_task1 + 0x0002)
                                    469 ;	main.c:122: restore_context();
      0000FE 85 08 81         [24]  470 	mov	_SP,_curSP
      000101 D0 D0            [24]  471 	pop	PSW
      000103 D0 01            [24]  472 	pop	ar1
      000105 D0 00            [24]  473 	pop	ar0
      000107 D0 07            [24]  474 	pop	ar7
      000109 D0 06            [24]  475 	pop	ar6
      00010B D0 05            [24]  476 	pop	ar5
      00010D D0 04            [24]  477 	pop	ar4
      00010F D0 03            [24]  478 	pop	ar3
      000111 D0 02            [24]  479 	pop	ar2
      000113 D0 F0            [24]  480 	pop	b
      000115 D0 83            [24]  481 	pop	DPH
      000117 D0 82            [24]  482 	pop	DPL
      000119 D0 E0            [24]  483 	pop	ACC
      00011B 32               [24]  484 	reti
                                    485 ;	main.c:124: while (1)
      00011C                        486 00102$:
                                    487 ;	main.c:126: }
      00011C 80 FE            [24]  488 	sjmp	00102$
                                    489 ;------------------------------------------------------------
                                    490 ;Allocation info for local variables in function 'delay_tick'
                                    491 ;------------------------------------------------------------
                                    492 ;tick                      Allocated to registers r6 r7 
                                    493 ;------------------------------------------------------------
                                    494 ;	main.c:128: void delay_tick(unsigned short tick)
                                    495 ;	-----------------------------------------
                                    496 ;	 function delay_tick
                                    497 ;	-----------------------------------------
      00011E                        498 _delay_tick:
      00011E AE 82            [24]  499 	mov	r6,dpl
      000120 AF 83            [24]  500 	mov	r7,dph
                                    501 ;	main.c:130: tick += _tick;
      000122 E5 09            [12]  502 	mov	a,__tick
      000124 2E               [12]  503 	add	a,r6
      000125 FE               [12]  504 	mov	r6,a
      000126 E5 0A            [12]  505 	mov	a,(__tick + 1)
      000128 3F               [12]  506 	addc	a,r7
      000129 FF               [12]  507 	mov	r7,a
                                    508 ;	main.c:131: while (_tick < tick)
      00012A                        509 00101$:
      00012A C3               [12]  510 	clr	c
      00012B E5 09            [12]  511 	mov	a,__tick
      00012D 9E               [12]  512 	subb	a,r6
      00012E E5 0A            [12]  513 	mov	a,(__tick + 1)
      000130 9F               [12]  514 	subb	a,r7
      000131 40 F7            [24]  515 	jc	00101$
                                    516 ;	main.c:133: }
      000133 22               [24]  517 	ret
                                    518 ;------------------------------------------------------------
                                    519 ;Allocation info for local variables in function 'switch_to'
                                    520 ;------------------------------------------------------------
                                    521 ;	main.c:135: void switch_to(void)
                                    522 ;	-----------------------------------------
                                    523 ;	 function switch_to
                                    524 ;	-----------------------------------------
      000134                        525 _switch_to:
                                    526 ;	main.c:137: if (curTask == TASK1)
      000134 E5 11            [12]  527 	mov	a,_curTask
      000136 70 0A            [24]  528 	jnz	00102$
                                    529 ;	main.c:139: task1.sp = curSP;
      000138 85 08 0D         [24]  530 	mov	(_task1 + 0x0002),_curSP
                                    531 ;	main.c:140: curTask = TASK2;
      00013B 75 11 01         [24]  532 	mov	_curTask,#0x01
                                    533 ;	main.c:141: curSP = task2.sp;
      00013E 85 10 08         [24]  534 	mov	_curSP,(_task2 + 0x0002)
      000141 22               [24]  535 	ret
      000142                        536 00102$:
                                    537 ;	main.c:145: task2.sp = curSP;
      000142 85 08 10         [24]  538 	mov	(_task2 + 0x0002),_curSP
                                    539 ;	main.c:146: curTask = TASK1;
      000145 75 11 00         [24]  540 	mov	_curTask,#0x00
                                    541 ;	main.c:147: curSP = task1.sp;
      000148 85 0D 08         [24]  542 	mov	_curSP,(_task1 + 0x0002)
                                    543 ;	main.c:149: }
      00014B 22               [24]  544 	ret
                                    545 ;------------------------------------------------------------
                                    546 ;Allocation info for local variables in function 'delay_us'
                                    547 ;------------------------------------------------------------
                                    548 ;us                        Allocated to registers 
                                    549 ;------------------------------------------------------------
                                    550 ;	main.c:151: void delay_us(unsigned short us)
                                    551 ;	-----------------------------------------
                                    552 ;	 function delay_us
                                    553 ;	-----------------------------------------
      00014C                        554 _delay_us:
      00014C AE 82            [24]  555 	mov	r6,dpl
      00014E AF 83            [24]  556 	mov	r7,dph
                                    557 ;	main.c:153: while (--us)
      000150                        558 00101$:
      000150 1E               [12]  559 	dec	r6
      000151 BE FF 01         [24]  560 	cjne	r6,#0xff,00111$
      000154 1F               [12]  561 	dec	r7
      000155                        562 00111$:
      000155 EE               [12]  563 	mov	a,r6
      000156 4F               [12]  564 	orl	a,r7
      000157 70 F7            [24]  565 	jnz	00101$
                                    566 ;	main.c:155: }
      000159 22               [24]  567 	ret
                                    568 ;------------------------------------------------------------
                                    569 ;Allocation info for local variables in function 'delay_ms'
                                    570 ;------------------------------------------------------------
                                    571 ;ms                        Allocated to registers 
                                    572 ;------------------------------------------------------------
                                    573 ;	main.c:156: void delay_ms(unsigned short ms)
                                    574 ;	-----------------------------------------
                                    575 ;	 function delay_ms
                                    576 ;	-----------------------------------------
      00015A                        577 _delay_ms:
      00015A AE 82            [24]  578 	mov	r6,dpl
      00015C AF 83            [24]  579 	mov	r7,dph
                                    580 ;	main.c:158: while (--ms)
      00015E                        581 00101$:
      00015E 1E               [12]  582 	dec	r6
      00015F BE FF 01         [24]  583 	cjne	r6,#0xff,00115$
      000162 1F               [12]  584 	dec	r7
      000163                        585 00115$:
      000163 EE               [12]  586 	mov	a,r6
      000164 4F               [12]  587 	orl	a,r7
      000165 60 10            [24]  588 	jz	00104$
                                    589 ;	main.c:159: delay_us(1000);
      000167 90 03 E8         [24]  590 	mov	dptr,#0x03e8
      00016A C0 07            [24]  591 	push	ar7
      00016C C0 06            [24]  592 	push	ar6
      00016E 12 01 4C         [24]  593 	lcall	_delay_us
      000171 D0 06            [24]  594 	pop	ar6
      000173 D0 07            [24]  595 	pop	ar7
      000175 80 E7            [24]  596 	sjmp	00101$
      000177                        597 00104$:
                                    598 ;	main.c:160: }
      000177 22               [24]  599 	ret
                                    600 ;------------------------------------------------------------
                                    601 ;Allocation info for local variables in function 'task1_func'
                                    602 ;------------------------------------------------------------
                                    603 ;	main.c:162: void task1_func(void)
                                    604 ;	-----------------------------------------
                                    605 ;	 function task1_func
                                    606 ;	-----------------------------------------
      000178                        607 _task1_func:
                                    608 ;	main.c:164: while (1)
      000178                        609 00102$:
                                    610 ;	main.c:166: P1_1 = !P1_1;
      000178 B2 91            [12]  611 	cpl	_P1_1
                                    612 ;	main.c:167: delay_tick(100);
      00017A 90 00 64         [24]  613 	mov	dptr,#0x0064
      00017D 12 01 1E         [24]  614 	lcall	_delay_tick
                                    615 ;	main.c:169: }
      000180 80 F6            [24]  616 	sjmp	00102$
                                    617 ;------------------------------------------------------------
                                    618 ;Allocation info for local variables in function 'task2_func'
                                    619 ;------------------------------------------------------------
                                    620 ;	main.c:171: void task2_func(void)
                                    621 ;	-----------------------------------------
                                    622 ;	 function task2_func
                                    623 ;	-----------------------------------------
      000182                        624 _task2_func:
                                    625 ;	main.c:173: while (1)
      000182                        626 00102$:
                                    627 ;	main.c:175: P2_1 = !P2_1;
      000182 B2 A1            [12]  628 	cpl	_P2_1
                                    629 ;	main.c:176: delay_tick(200);
      000184 90 00 C8         [24]  630 	mov	dptr,#0x00c8
      000187 12 01 1E         [24]  631 	lcall	_delay_tick
                                    632 ;	main.c:178: }
      00018A 80 F6            [24]  633 	sjmp	00102$
                                    634 ;------------------------------------------------------------
                                    635 ;Allocation info for local variables in function 'timer0_init'
                                    636 ;------------------------------------------------------------
                                    637 ;	main.c:180: void timer0_init(void)
                                    638 ;	-----------------------------------------
                                    639 ;	 function timer0_init
                                    640 ;	-----------------------------------------
      00018C                        641 _timer0_init:
                                    642 ;	main.c:182: TMOD += 0x01;
      00018C E5 89            [12]  643 	mov	a,_TMOD
      00018E 04               [12]  644 	inc	a
      00018F F5 89            [12]  645 	mov	_TMOD,a
                                    646 ;	main.c:183: TH0 = 0xdb;
      000191 75 8C DB         [24]  647 	mov	_TH0,#0xdb
                                    648 ;	main.c:184: TL0 = 0xff;
      000194 75 8A FF         [24]  649 	mov	_TL0,#0xff
                                    650 ;	main.c:185: }
      000197 22               [24]  651 	ret
                                    652 ;------------------------------------------------------------
                                    653 ;Allocation info for local variables in function 'timer0_start'
                                    654 ;------------------------------------------------------------
                                    655 ;	main.c:187: void timer0_start(void)
                                    656 ;	-----------------------------------------
                                    657 ;	 function timer0_start
                                    658 ;	-----------------------------------------
      000198                        659 _timer0_start:
                                    660 ;	main.c:189: TR0 = 1;
                                    661 ;	assignBit
      000198 D2 8C            [12]  662 	setb	_TR0
                                    663 ;	main.c:190: }
      00019A 22               [24]  664 	ret
                                    665 	.area CSEG    (CODE)
                                    666 	.area CONST   (CODE)
                                    667 	.area XINIT   (CODE)
                                    668 	.area CABS    (ABS,CODE)
