import time
import simpleaudio as sa
import random
import sys
from sys import stdin
from threading import Thread
import os
from midiutil.MidiFile import MIDIFile

#defineren van default samples
kick = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Snare.wav")
hat = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Hat.wav")

#aanmaken lijsten
global randlist
snareAccent=[]


#Afspeel functies
def playKick():
	kick.play()

def playHihat():
	hat.play()

def playSnare():
	snare.play()






#rand word gebruikt om te bepalen of een instrument mag worden gespeelt of niet.
#als deze functie wordt aangesproken moet er een precentage worden meegegeven.
#vervolgens zal er random een getal uit een van de lijsten worden gekozen afhankelijk van het precentage.
#de uitkomt kan 1 of 0 zijn en wordt terug gegeven.
def rand(procent):
	if (procent == 100):
		randlist = [1,1,1,1,1]
	elif (procent == 80):
		randlist = [1,0,1,1,1]
	elif (procent == 60):
		randlist = [1,1,0,1,0]
	elif (procent == 40):
		randlist = [1,0,1,0,0]
	elif (procent == 20):
		randlist = [0,0,1,0,0]
	else:
		randlist = [0,0,0,0,0]

	result = random.choice(randlist)

	return result


	




#Het aanmaken van een grid gebeurd aan de hand van de gekozen maatsoort.
#Hieronder worden verschillende lijsten aangemaakt met procent waarden.
#Ook wordt een gridsize meegegeven. Dit is voor het afspelen later.
def createGrid(beat):
	global gridSize
	if (beat == "4/4"):
		
		gridSize=16

		#maak variabelen globaal zodat ze buiten de functie leesbaar zijn.
		#maak tevens lijsten met procenten en reserveer plaatsen in de playlist.
		#Kick
		global kickAccent
		kickAccent=[100,0,40,20,0,0,20,0,20,0,80,20,0,0,0,0]
		global kickPlayList
		kickPlayList=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

		#Snare
		global snareAccent
		snareAccent=[0,0,0,0,100,0,0,60,0,80,0,0,100,0,20,40,0]
		global snarePlayList
		snarePlayList=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

	elif (beat == "5/4"):
		gridSize=20
		
		#Kick
		kickAccent=[100,0,40,0,0,0,0,0,100,0,20,0,0,0,60,0,0,0,100,0,0]
		kickPlayList=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
		
		#Snare
		snareAccent=[0,0,0,0,100,0,0,0,0,0,40,0,100,0,0,0,60,0,0,0,0]
		snarePlayList=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	
	elif (beat == "7/4"):
		gridSize=28

		#Kick
		kickAccent=[100,0,0,0,0,0,80,0,60,0,60,0,0,0,60,0,60,0,40,0,40,0,60,0,0,0,0,0,0]
		kickPlayList=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

		#Snare
		snareAccent=[0,0,0,0,80,0,0,0,40,0,0,0,80,0,40,0,0,0,40,0,60,0,60,0,60,0,80,0]
		snarePlayList=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	






#Hier worden de afspeel lijsten gegenereerd.
#Dit gebeurd aan de hand van de lijsten die bij createGrid zijn gegenereerd
def createPlaylists(beat):
	
	#create Playlist voor 4/4e maatsoort
	if (beat=="4/4"):
		gridNum=0
		
		#Kick
		while gridNum<gridSize:
			#regels zodat er een keuze wordt gemaakt wanneer een kick wel of niet mag worden gespeelt
			if (gridNum==3) and (kickPlayList[2]>0):
				kickPlayList[3]=0
			elif (gridNum==11) and (kickPlayList[10]>0):
				kickPlayList[11]=0
			else:
				kickPlayList[gridNum]=rand(kickAccent[gridNum])
			gridNum += 1

		#Snare
		gridNum=0
		while gridNum<gridSize:
			#regels voor de snare wanneer wel en niet mag worden gespeelt.
			if (gridNum==15) and (snarePlayList[14]>0):
				snarePlayList[15]=0
			else:
				snarePlayList[gridNum]=rand(snareAccent[gridNum])

			gridNum += 1

		global hatPlayList
		hatPlayList=[1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0]





	#create Playlist voor 5/4e maatsoort
	if (beat=="5/4"):
		gridNum=0
		
		#Kick
		while gridNum<gridSize:
			kickPlayList[gridNum]=rand(kickAccent[gridNum])
			gridNum += 1

		#Snare
		gridNum=0
		while gridNum<gridSize:
			snarePlayList[gridNum]=rand(snareAccent[gridNum])

			#accent = snareAccent[gridNum]
			#snarePlayList[gridNum]=rand(accent)

			gridNum += 1
		
		hatPlayList=[1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0]




	#create Playlist voor 7/4e maatsoort
	if (beat=="7/4"):
		gridNum=0
		
		#Kick
		while gridNum<gridSize:
			kickPlayList[gridNum]=rand(kickAccent[gridNum])
			gridNum += 1

		#Snare
		gridNum=0
		while gridNum<gridSize:
			if(kickPlayList[gridNum]>0):
				snarePlayList[gridNum]=0
			else:
				snarePlayList[gridNum]=rand(snareAccent[gridNum])

			gridNum += 1
		
		hatPlayList=[1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0]

	#geef de gegenereerde beat weer in de console
	print("Kick Playlist   : ", kickPlayList)
	print("Snare Playlist  : ", snarePlayList)
	print("Hihat Playlist  : ", hatPlayList)










#de commandline luisterd op de achtergrond altijd naar bepaalde commandos
#zo kan de gebruiker kiezen om bepaalde dingen uit te voeren terwijl bijv. de beat speelt.
def commandListener():
	while True:
		userInput = input("Command: ");
		if (userInput=="new"):
			print("------------Nieuwe Beat-------------")
			createPlaylists(maatsoort)
		elif (userInput=="exit"):
			print("Bedankt voor het gebruik van Beatmachine")
			print("-------------Tot Ziens--------------")
			os._exit(1)
		elif (userInput=="save"):
			createMidiFile()
			createPlaylists(maatsoort)
			print("------------Nieuwe Beat-------------")
			print("Als u de beat wilt opslaan gebruik het commando 'save'")
		elif (userInput=="help"):
			print("-----------------Help------------------")
			print("---------------------------------------")
			print("|new-------Genereer nieuwe beat-------|")
			print("|save------Sla beat op in midi bestand|")
			print("|exit------Sluit Beatmachine af-------|")
			print("---------------------------------------")
			print("---------------------------------------")









def sampleSelector():
	#vraagt het pad aan de gebruiker.
	#hij/zij kan de sample in het venster droppen zodat het pad wordt over genomen.

	##Vraag om een nieuwe kijk file. Bij fout opnieuw probeeren.
	while True:
		try:
			kickFilename = input("Drop hier je kick sample: ")
			kick = sa.WaveObject.from_wave_file(kickFilename)
			break
		except FileNotFoundError:
			print("Het pad is niet juist. Probeer het opnieuw")
	print("De kick is succesvol geselecteerd met bestandsnaam: ", kickFilename)
	print("------------------------------------")

	#Vraag om een nieuwe snare file. Bij fout opnieuw probeeren.
	while True:
		try:
			snareFilename = input("Drop hier je snare sample: ")
			snare = sa.WaveObject.from_wave_file(snareFilename)
			break
		except FileNotFoundError:
			print("Het pad is niet juist. Probeer het opnieuw")
	print("De snare is succesvol geselecteerd met bestandsnaam: ", snareFilename)
	print("------------------------------------")

	#Vraag om een nieuwe hihat file. Bij fout opnieuw probeeren.
	while True:
		try:
			hatFilename = input("Drop hier je hihat sample: ")
			hat = sa.WaveObject.from_wave_file(hatFilename)
			break
		except FileNotFoundError:
			print("Het pad is niet juist. Probeer het opnieuw")
	print("De hihat is succesvol geselecteerd met bestandsnaam: ", hatFilename)
	print("------------------------------------")









#speel de gegenereerde beat af.
def play():
	
	#bereken het aantal miliseconden
	noteDuration = (60/bpm)/4


	gridNum=0
	while True:

		#speel kick bij het lezen van een 1
		if (kickPlayList[gridNum]==1):
			playKick()

		#speel snare bij het lezen van een 1
		if (snarePlayList[gridNum]==1):
			playSnare()

		#speel hihat bij het lezen van een 1
		if (hatPlayList[gridNum]==1):
			playHihat()

		#stap extra op de grid
		gridNum += 1

		#reset de grid voor het loopen.
		if (gridNum==gridSize):
			gridNum=0

		#wacht even een aantal miliseconden. Deze is gelijk aan het aantap beats per minuut
		time.sleep(noteDuration)









#met deze functie wordt er een midifile aangemaakt.
def createMidiFile():
	
	mf = MIDIFile(1)   
	track = 0   

	time = 0    
	mf.addTrackName(track, time, "BeatMachine")
	mf.addTempo(track, time, bpm)

	#voeg noten toe aan midi file
	channel = 0
	volume = 100

	for x in range(0,len(kickPlayList)):
		if (kickPlayList[x]==1):
			pitch = 36           
			time = x/4             
			duration = 0.5         
			mf.addNote(track, channel, pitch, time, duration, volume)

		if (snarePlayList[x]==1):
			pitch = 38           
			time = x/4             
			duration = 0.5         
			mf.addNote(track, channel, pitch, time, duration, volume)

		if (hatPlayList[x]==1):
			pitch = 42         
			time = x/4          
			duration = 0.5   
			mf.addNote(track, channel, pitch, time, duration, volume)

	# schijf midi file weg naar hdd
	with open("BeatMachine.mid", 'wb') as outf:
	    mf.writeFile(outf)

	#laat de gebruiker weten dat de beat is opgeslagen
	print("Beat is weggeschreven in het midi bestand.")










#deze functie is voornamelijk de gebruikers interface waar de gebruiker mee werkt.
def commandline():
	print("_______________Welkom!______________")
	print("____________Beat Machine____________")
	print("------------------------------------")




	#Vraagt de gebruiker om het aantal bpm
	global bpm
	while True:
		try:
			bpm = int(input("Voer het gewenste beats per minute in: "))
			
			break
		except Exception:
			print("probleem")
	print("U heeft ", bpm, " Bpm ingevuld!")
	print("------------------------------------")





	#vraagt de gebruiker om de maatsoort in te voeren.
	global maatsoort
	while True:
		maatsoort= input("Vul de gewenste maatsoort in. U kunt kiezen uit: 4/4, 5/4 en 7/4: ")
		if (maatsoort == "4/4" or (maatsoort == "5/4") or (maatsoort == "7/4")):
			break
		else:
			#wanneer input niet matched een foutmelding geven.
			print("U heeft een foutieve maatsoort ingevoerd. Probeer het opnieuw")
	print("U heeft voor de ", maatsoort, " maatsoort gekozen!")
	print("------------------------------------")




	#vraagt de gebruiker of hij/zij eigensamples wil gebruiken
	#bij ja zal het programma voor iedere partij een sample vragen.
	#wanneer een foutief antwoord is gegeven zal er gevraagt worden om het opnieuw te proberen.
	while True:
		ownSamples = input("Wil u eigen samples gebruiken? Gebruik J voor Ja of N voor Nee: ")
		if (ownSamples == "J") or (ownSamples == "j"):
			print("U heeft evoor gekozen om eigen samples te kiezen.")
			sampleSelector()
			break
		elif (ownSamples == "N") or (ownSamples == "n"):
			print("U heeft ervoor gekozen om geen gebruik te maken van eigen samples.")
			print("Er wordt gebruik gemaakt van de default samples")
			break
		else:
			print("U heeft ", ownSamples, " ingevoerd. Probeer het opnieuw")




	#informatie naar gebruiker
	print("------------------------------------")
	print("Voor hulp, gebruik het commando Help")
	print("-----Beat wordt nu gegenereerd------")




	#genereer een beat doormiddeld van de ingevulde gegevens.
	createGrid(maatsoort)
	createPlaylists(maatsoort)

	print("Als u de beat wilt opslaan gebruik het commando 'save'")

	#laad de commandlistener zodat de gebruiker interactie kan hebben met de applicatie
	t = Thread(target=commandListener)
	t.start()

	#speel automatisch de beat af.
	play()
	
#maak de terminal schoon van alle commands
os.system("clear")

#start applicatie
commandline()