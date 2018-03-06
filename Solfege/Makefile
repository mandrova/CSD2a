CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : sine.o oscillator.o jack_module.o mtofConverter.o Screen.o musicianModule.o musicianModuleMenu.o IntervalTrainer.o IntervalGenerator.o Interval.o AudioPlayer.o Synthesiser.o SolfegeSynth.o main.o 
	$(CC) -o $@ $(CFLAGS) sine.o oscillator.o jack_module.o mtofConverter.o Screen.o musicianModule.o musicianModuleMenu.o IntervalTrainer.o IntervalGenerator.o Interval.o AudioPlayer.o Synthesiser.o SolfegeSynth.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
