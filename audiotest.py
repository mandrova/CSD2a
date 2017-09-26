import simpleaudio as sa
import time

kick = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Snare.wav")
hat = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Hat.wav")

bpm = int(input("Voer het aantal bpm in: "))
bpm = (60/bpm)/4 

x = 0
while x<10:
	#1
	kick.play()
	hat.play()
	time.sleep(bpm)
	#2
	time.sleep(bpm)
	#3
	hat.play()
	time.sleep(bpm)
	#4
	time.sleep(bpm)

	#1
	kick.play()
	snare.play()
	hat.play()
	time.sleep(bpm)
	#2
	time.sleep(bpm)
	#3
	hat.play()
	time.sleep(bpm)
	#4
	time.sleep(bpm)

	#1
	kick.play()
	hat.play()
	time.sleep(bpm)
	#2
	time.sleep(bpm)
	#3
	hat.play()
	time.sleep(bpm)
	#4
	time.sleep(bpm)

	#1
	kick.play()
	snare.play()
	hat.play()
	time.sleep(bpm)
	#2
	time.sleep(bpm)
	#3
	hat.play()
	time.sleep(bpm)
	#4
	time.sleep(bpm)

	x+=1