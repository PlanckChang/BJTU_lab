	.data
A:  .word 10
B:  .word 8
C:  .word 0
CR: .word32 0x10000
DR: .word32 0x10008

      .text
main:
      ld  r4, A(r0)
      ld  r5, B(r0)
      dadd  r3, r4, r5
      sd  r3, C(r0)

      lwu r1, CR(r0) ; Control Register
      lwu r2, DR(r0) ; Data Register
      daddi r10, r10, 1
      sd r3, (r2)  ; r3 output
      sd r10, (r1) ; .. to screen

      halt