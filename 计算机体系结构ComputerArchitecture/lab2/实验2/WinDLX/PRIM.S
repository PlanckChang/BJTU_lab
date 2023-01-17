;*********** WINDLX Exp.2: Generate prime number table *************
;*********** (c) 1991 Günther Raidl		       *************
;*********** Modified 1992 Maziar Khosravipour	       *************

;-------------------------------------------------------------------
; Program begins at symbol main
; generates a table with the first 'Count' prime numbers from 'Table'
;-------------------------------------------------------------------

		.data

		;*** size of table
		.global		Count
Count:		.word		10
		.global		Table
Table:		.space		Count*4


		.text
		.global	main
main:
		;*** Initialization
		addi		r1,r0,0		;Index in Table
		addi		r2,r0,2 	;Current value

		;*** Determine, if R2 can be divided by a value in table
NextValue:	addi		r3,r0,0 	;Helpindex in Table
Loop:		seq		r4,r1,r3	;End of Table?
		bnez		r4,IsPrim	;R2 is a prime number
		lw		r5,Table(R3)
		divu		r6,r2,r5
		multu		r7,r6,r5
		subu		r8,r2,r7
		beqz		r8,IsNoPrim
		addi		r3,r3,4
		j		Loop

IsPrim: 	;*** Write value into Table and increment index
		sw		Table(r1),r2
		addi		r1,r1,4

		;*** 'Count' reached?
		lw		r9,Count
		srli		r10,r1,2
		sge		r11,r10,r9
		bnez		r11,Finish

IsNoPrim:	;*** Check next value
		addi		r2,r2,1 	;increment R2
		j		NextValue
		
Finish: 	;*** end
		trap		0