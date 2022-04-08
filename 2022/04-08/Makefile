CC = g++
CFLAGS = -g -Wall

all: main

main: main.o KthLargest.o
	$(CC) $(CFLAGS) -o main main.o KthLargest.o

main.o: main.cpp KthLargest.h KthLargest.o
	$(CC) $(CFLAGS) -c main.cpp

KthLargest.o: KthLargest.cpp KthLargest.h
	$(CC) $(CFLAGS) -c KthLargest.cpp
clean:
	rm main *.o
