CC=gcc
CFLAGS=-Wall -g -lSDL2 -lSDL2_gfx

all: main
	./main

main: main.o process_events.o render.o logic.o
	$(CC) $(CFLAGS) main.o render.o process_events.o logic.o -o main

main.o: main.c game.h process_events.h render.h
	$(CC) $(CFLAGS) -c main.c

process_events.o: process_events.c game.h logic.h
	$(CC) $(CFLAGS) -c process_events.c

render.o: render.c game.h
	$(CC) $(CFLAGS) -c render.c

logic.o: logic.c game.h
	$(CC) $(CFLAGS) -c logic.c

clean:
	rm main *.o
