share.o: share.c share.h
	gcc -c share.c
main_share.o: main_share.c share.h
	gcc -c main_share.c
launch: main_share.o share.o
	gcc main_share.o share.o -o launch
run: launch
	./launch