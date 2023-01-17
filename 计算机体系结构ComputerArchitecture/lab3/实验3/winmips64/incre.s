      .data
number: .word32 1, 2, 3, 4, 5, 6, 7, 8, 9
       .text
main:
      daddi  r2, r0, number
      daddi  r3, r2, 24
loop: lw  r1, 0(r2)


      daddi  r1, r1, 1
      sw  r1, 0(r2)
      daddi  r2, r2, 4 
      dsub  r4, r3, r2
      bnez  r4, loop   
      
      daddi  r5, r0, 0
      daddi  r6, r0, 0
      halt