# Make file for Lab4, CSCI2270
#
# This makefile is used as follows to regenerate files for the BigNum program:
#   make BigNum.o   --  Regenerates BigNum.o by compiling
#   make TestLab4.o   --  Regenerates TestLab4.o by compiling
#   make TestLab4 --  Regenerates the executable TestLab4 file by compiling
#   make              --  Same as "make TestLab4" (since TestLab4 is 
#                     --  the 1st target)
#
# Two special targets may also be used with this makefile:
#   make all          --  Regenerates all files listed above
#   make clean        --  Erases all files listed above
#
# All compilations occur with -Wall and -g.
# The clean command uses rm to remove all expendable files (rm is part of
# the cs1300 compiler tools from www.cs.colorado.edu/~main/cs1300/README.html).

# define the different outputs of all g++ commands
# on Ubuntu, the .exe suffix disappears
EXPENDABLES = BigNum.o TestLab4.o TestLab4

# make all is listed first, which lets you type "make" to recompile 
# anything that has changed in either your class, your test code, 
# or my test code.
all:
	@make $(EXPENDABLES)

# this compiles your test program and your BigNum class together
TestLab4: TestLab4.o BigNum.o
	g++ -Wall -g BigNum.o TestLab4.o -lm -o TestLab4 

# this compiles your BigNum class, which isn't executable (no main)
BigNum.o: BigNum.h BigNum.cxx
	g++ -Wall -g -c BigNum.cxx -o BigNum.o

# this compiles your test program, which is executable
TestLab4.o: BigNum.h TestLab4.cxx
	g++ -Wall -g -c TestLab4.cxx -o TestLab4.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)
