      .data
number: .word32 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
       .text
main:
      daddi  r2, r0, number
      daddi  r3, r2, 48
      
loop: lw  r1, 0(r2)
      daddi  r2, r2, 4 
      daddi  r1, r1, 1
      dsub  r4, r3, r2
      sw  r1, -4(r2)  
      bnez  r4, loop
 
      daddi  r5, r0, 0
      daddi  r6, r0, 0
      halt