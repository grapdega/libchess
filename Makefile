CC=gcc
CFLAG=-Wall -g
all: clean build run
clean:
	rm -f libchess.so
	rm -f chess-game

build:
	$(CC) $(CFLAGS) board.c -I. -fPIC -shared -o libchess.so
	$(CC) $(CFLAGS) -I. -L. main.c -lchess -o chess-game

run:
	LD_LIBRARY_PATH=:$LD_LIBRARY_PATH:`pwd` ./chess-game
