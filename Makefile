CC = gcc
CFLAGS = -g -Wall

all: StrList

StrList: Main.o StrList.o
	$(CC) $(CFLAGS) -o StrList Main.o StrList.o

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c Main.c

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c StrList.c

clean:
	rm -f *.o *.a *.so StrList