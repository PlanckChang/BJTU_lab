;*********** WINDLX Ex.3: JZ Test
;--------------------------------------------------------------------------

		.data
buffer: 	.space		8


		.text
		.global	main
main:
		xor		r0,r0,r0
		addi		r1,r0,1
		addi		r2,r0,2
		addi		r4,r2,5
		sw		buffer,r1

		addi		r2,r0,2
		j		Finish

Finish:
		;*** end
		trap		0

