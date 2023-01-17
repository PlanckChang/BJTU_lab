;*********** WINDLX Ex.1: Greatest common measure *************
;*********** (c) 1991 Günther Raidl		  *************
;*********** Modified 1992 Maziar Khosravipour	  *************

;------------------------------------------------------------------------
; Program begins at symbol main
; requires module INPUT
; Read two positive integer numbers from stdin, calculate the gcm
; and write the result to stdout
;------------------------------------------------------------------------

		.data

		;*** Prompts for input
Prompt1:	.asciiz 	"First Number:"
Prompt2:	.asciiz 	"Second Number: "

		;*** Data for printf-Trap
PrintfFormat:	.asciiz 	"gcM=%d\n\n"
		.align		2
PrintfPar:	.word		PrintfFormat
PrintfValue:	.space		4


		.text
		.global	main
main:
		;*** Read two positive integer numbers into R1 and R2
		addi		r1,r0,Prompt1
		jal		InputUnsigned	;read uns.-integer into R1
		add		r2,r1,r0	;R2 <- R1
		addi		r1,r0,Prompt2
		jal		InputUnsigned	;read uns.-integer into R1

Loop:		;*** Compare R1 and R2
		seq		r3,r1,r2	;R1 == R2 ?
		bnez		r3,Result	
		sgt		r3,r1,r2	;R1 > R2 ?
		bnez		r3,r1Greater
		
r2Greater:	;*** subtract r1 from r2
		sub		r2,r2,r1
		j		Loop

r1Greater:	;*** subtract r2 from r1
		sub		r1,r1,r2
		j		Loop

Result: 	;*** Write the result (R1)
		sw		PrintfValue,r1
		addi		r14,r0,PrintfPar
		trap		5

		;*** end
		trap		0