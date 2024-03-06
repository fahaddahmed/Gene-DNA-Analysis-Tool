my_program: functions.o main.o
	gcc functions.o main.o -o my_program -lm

functions.o: functions.c
	gcc -Wall -std=c99 -c functions.c

main.o: main.c
	gcc -Wall -std=c99 -c main.c

clean:
	rm -f *.o my_program

