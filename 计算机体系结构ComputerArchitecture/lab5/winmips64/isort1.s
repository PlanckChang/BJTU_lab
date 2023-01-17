#
# Insertion sort algorithm
# See http://www.cs.ubc.ca/spider/harrison/Java/InsertionSortAlgorithm.java.html
# Note use of MIPS register pseudo-names, and # for comments
#
      .data 
array: .word  0x4F6961869342DC99,0x7A0B67101C85D9EE,0x5EF87A2B37CA911D,0x47EF58E8B7E01DD9
       .word  0x79A74EAB20CB53C9,0x6D26753D06F8E483,0x70F313AF126C0B47,0x745232A4035F1EF5
       
len:  .word 8


        .text
        daddi $t0,$zero,8  # $t0 = i = 8
        ld $t1,len($zero)  # $t1 = len
        dsll $t1,$t1,3     # $t1 = len*8
for:    slt $t2,$t0,$t1    # i < len?
        beqz $t2,out       # yes - exit
        dadd $t3,$zero,$t0 # $t3=j=i
        ld $t4,array($t0)  # $t4=B=a[i]
loop:   slt $t2,$zero,$t3  # j>0 ?
        beqz $t2,over      # no -exit
        daddi $t5,$t3,-8   # $t5=j-1
        ld $t6,array($t5)  # get $t6=a[j-1]
        slt $t2,$t6,$t4    # >B ?
        beqz $t2,over	 
        sd $t6,array($t3)  # a[j]=a[j-1]
        dadd $t3,$zero,$t5 # j--
        j loop

over:   sd $t4,array($t3)  # a[j] = B
        daddi $t0,$t0,8    # i++
        j for
out:    halt
   
