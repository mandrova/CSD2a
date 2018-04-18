CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : Delay.o Effect.o ringbuffer.o jack_module.o main.o
	$(CC) -o $@ $(CFLAGS) Delay.o Effect.o ringbuffer.o jack_module.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
