all: wordCounter

wordCounter:  wordCounter.o
	gcc -g -Wall -o wordCounter wordCounter.o

wordCounter.o: wordCounter.c
	gcc -g -Wall -c -o wordCounter.o wordCounter.c

clean:
	rm -f *.o
 
