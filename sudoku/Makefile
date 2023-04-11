CC = gcc -Wall -ansi -pedantic

all: sudoku.o grid.o
	$(CC) -o sudoku $^
	rm -rf *.o
	
test: sudoku
	./sudoku < test.in > test.tmp
	diff test.tmp test.out
	rm test.tmp
	
grid.o: grid.c grid.h
	$(CC) -c -o $@ $<

sudoku.o: sudoku.c grid.h sudoku.h
	$(CC) -c -o $@ $<

clean:
	rm -rf *.o
	rm sudoku
	touch *
