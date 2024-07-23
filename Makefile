OPCIONS = -fopenmp -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

all: main.exe


main.exe: main.o Tree.o
	g++ $(OPCIONS) -o main.exe main.o Tree.o

main.o: main.cc
	g++ $(OPCIONS) -c main.cc

Tree.o: Tree.cc Tree.hh
	g++ $(OPCIONS) -c Tree.cc

zip: Makefile Tree.cc Tree.hh main.cc 
	zip Projecte-A-Q1-23-24-Grup15.zip *.cc *.hh *.pdf *.ipynb *.md Makefile 

clean: 
	rm *.o *.exe  
