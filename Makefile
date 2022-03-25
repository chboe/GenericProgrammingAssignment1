sanitizers =-fsanitize=address -fsanitize=leak -fsanitize=undefined
flags := -Wall -Iinclude -std=c++2a -g -O2 $(SANFLAGS)
exercise1: List Tree main
	g++-10 $(sanitizers) main.o List.o Tree.o -o a.out
%:
	g++-10 $(flags) -c -o $@.o $@.cpp