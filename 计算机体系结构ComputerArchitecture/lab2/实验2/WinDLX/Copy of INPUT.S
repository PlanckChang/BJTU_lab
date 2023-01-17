;*********** WINDLX Ex.1: Read a positive integer number *************
;*********** (c) 1991 Günther Raidl			 *************
;*********** Modified 1992 Maziar Khosravipour		 *************

;-----------------------------------------------------------------------------
;Subprogram call by symbol "InputUnsigned"
;expect the address of a zero-terminated prompt string in R1
;returns the read value in R1
;changes the contents of registers R1,R13,R14
;-----------------------------------------------------------------------------

		.data

		;*** Data for Read-Trap
ReadBuffer:	.space		80
ReadPar:	.word		0,ReadBuffer,80

		;*** Data for Printf-Trap
PrintfPar:	.space		4

SaveR2:		.space		4
SaveR3:		.space		4
SaveR4:		.space		4
SaveR5:		.space		4


		.text

		.global		InputUnsigned
InputUnsigned:	
		;*** save register contents
		sw		SaveR2,r2
		sw		SaveR3,r3
		sw		SaveR4,r4
		sw		SaveR5,r5

		;*** Prompt
		sw		PrintfPar,r1
		addi		r14,r0,PrintfPar
		trap		5

		;*** call Trap-3 to read line
		addi		r14,r0,ReadPar
		trap		3

		;*** determine value
		addi		r2,r0,ReadBuffer
		addi		r1,r0,0
		addi		r4,r0,10	;Decimal system

Loop:		;*** reads digits to end of line
		lbu		r3,0(r2)
		seqi		r5,r3,10	;LF -> Exit
		bnez		r5,Finish
		subi		r3,r3,48	;´0´
		multu		r1,r1,r4	;Shift decimal
		add		r1,r1,r3
		addi		r2,r2,1 	;increment pointer
		j		Loop
		
Finish: 	;*** restore old register contents
		lw		r2,SaveR2
		lw		r3,SaveR3
		lw		r4,SaveR4
		lw		r5,SaveR5
		jr		r31		; Return