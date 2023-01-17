THIS SOFTWARE IS MADE AVAILABLE WITH PERMISSION FROM TECHNISCHE UNIVERSITAT WIEN, INSTITUTE FOR TECHNISCHE INFORMATIK.  MORGAN KAUFMANN PUBLISHERS ACCEPTS NO RESPONSIBILITY AND MAKES NO GUARANTEES FOR THIS SOFTWARE.  ANY DAMAGES WHICH MAY RESULT FROM INSTALLING AND/OR USING THIS SOFTWARE ARE THE RESPONSIBILITY OF THE SOFTWARE USER ONLY.  MORGAN KAUFMANN PERSONNEL ARE NOT QUALIFIED TO PROVIDE HELP OR ANSWER QUESTIONS REGARDING THE INSTALLATION AND/OR USE OF THIS SOFTWARE.

=================================================================


WinDLX DLX-Pipeline Simulator
(c) Copyright 1992 by by TU Vienna, Inst. for Technische Informatik
DLX simulator (c) Copyright 1989 by Regents of the University of California

This README contains information for the first-time installation of WinDLX.


What is WinDLX?
---------------
WinDLX is a pipeline simulator for the DLX processor as described in

                                      Computer Architecture:
                          A Quantitative Approach, Second Edition
                             by John Hennessy and Dave Patterson

               Morgan Kaufmann Publishers, San Francisco, California

It is a MS-Windows based front-end for the text-only DLX simulator available
via anonymous FTP from Stanford (max.stanford.edu).

After loading a symbolic DLX assembler code, most of the information relevant
to the CPU (pipeline, registers, I/O, memory, ...) can be viewed and modified
while executing the code step-by-step or continuously. WinDLX offers statistics
about pipeline behavior in time.

This program is designed to help people understand pipelining concepts as well
as other architectural specifics of RISC processors.


System prerequisites
--------------------
IBM personal computer or compatible with DOS 3.3 or later and Microsoft
Windows 3.0 or newer.


Installation
------------
The file WINDLX_D.EXE on this diskette is a self-extracting archive.
To unpack it, follow these steps:

1.) create a directory "WINDLX" somewhere on your hard drive and make this
    directory your current.

2.) type in the following line:

		A:\WINDLX\WINDLX_D

    This will unpack the files in the archive and install them on the hard drive.

    The following files will be created:

       WINDLX.EXE -- the WinDLX executable
       WINDLX.HLP -- Windows helpfile
       *.S        -- sample assembler input files
       README     -- this file
           .....


3.) Install the program into the Program Manager and click on the symbol to
    start it. The help facility is very extensive and covers almost everything
    we could think of.


Feel free to create your own assembler files and experiment with different
CPU configurations.

