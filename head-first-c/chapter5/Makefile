union.o: union.c union.h
	gcc -c union.c
enum.o: enum.c enum.h
	gcc -c enum.c
main.o: main.c main.h union.h enum.h
	gcc -c main.c
launch: union.o main.o
	gcc union.o enum.o main.o -o launch
run: launch
	./launch