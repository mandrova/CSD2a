CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: synthesizer

synthesizer : sine.o oscillator.o jack_module.o Screen.o IntervalGenerator.o Interval.o AudioPlayer.o Synthesizer.o SolfegeSynth.o main.o 
	$(CC) -o $@ $(CFLAGS) sine.o oscillator.o jack_module.o Screen.o IntervalGenerator.o Interval.o AudioPlayer.o Synthesizer.o SolfegeSynth.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
