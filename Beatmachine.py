import time
import simpleaudio as sa
import random
import sys
from sys import stdin
import _thread
import os

#defineren van samples
kick = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Kick.wav")
snare = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Snare.wav")
hat = sa.WaveObject.from_wave_file("/Users/nickverbeek/Documents/CSD2a/Audio files/Hat.wav")

#aanmaken lijsten
randlist=[0,0,0,0,0]
accenten=[]
gridSize=0
kickPlayList=[0]
kickAccent=[0]
snareAccent=[0]

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
		randlist=[1,1,1,1,1]
	elif (procent == 80):
		randlist=[1,0,1,1,1]
	elif (procent == 60):
		randlist=[0,0,1,1,1]	
	elif (procent == 40):
		randlist=[0,0,1,0,1]
	elif (procent == 20):
		randlist=[0,0,1,0,0]

	result = random.choice(randlist)

	return result

#Het aanmaken van een grid gebeurd aan de hand van de gekozen maatsoort.
#Hieronder worden verschillende lijsten aangemaakt met procent waarden.
#Ook wordt een gridsize meegegeven. Dit is voor het afspelen later.
def createGrid(beat):
	if (beat == "4/4"):
		gridSize=16
		kickAccent=[100,0,40,20,0,0,20,0,20,0,80,20,0,0,0,0]
		snareAccent=[0,0,0,0,100,0,0,60,0,0,80,0,0,100,0,20,40]
	elif (beat == "5/4"):
		gridSize=20
		accenten=[2,0,0,1,0,2,0,0,1,0,2,0,0,1,0,2,0,0,1,0]
	elif (beat == "7/4"):
		gridSize=28
		accenten=[2,0,0,1,0,0,1,0,2,0,0,1,0,0,1,0,2,0,0,1,0,0,1,0,2,0,0,1,0,0,1,0]

#Hier worden de afspeel lijsten gegenereerd.
#Dit gebeurd aan de hand van de lijsten die bij createGrid zijn gegenereerd
def createPlaylists():
	gridNum=0
	while gridNum<gridSize+1:
		accent = kickAccent[gridNum]
		if (gridNum==3) and (kickPlayList[2]>0):
			kickPlayList[3]=0
		elif (gridNum==11) and (kickPlayList[10]>0):
			kickPlayList[11]=0
		else:
			kickPlayList[gridNum]=rand(accent)

		accent = snareAccent[gridNum]
		snarePlayList[gridNum]=rand(accent)

		gridNum += 1


#de commandline luisterd op de achtergrond altijd naar bepaalde commandos
#zo kan de gebruiker kiezen om bepaalde dingen uit te voeren terwijl bijv. de beat speelt.
def commandListener():
	userInput = sys.stdin.read(8)
	if (userInput=="play"):
		print("Play")
	elif (userInput=="stop"):
		print("Stop")
	elif (userInput=="new"):
		print("New")
	elif (userInput=="help"):
		print("-----------------Help------------------")
		print("---------------------------------------")
		print("|play------Afspelen van de beat-------|")
		print("|stop------Stoppen van de beat--------|")
		print("|new-------Genereer nieuwe beat-------|")
		print("|exit------Sluit Beatmachine af-------|")
		print("---------------------------------------")
		print("---------------------------------------")

def sampleSelector():
	#vraagt het pad aan de gebruiker.
	#hij/zij kan de sample in het venster droppen zodat het pad wordt over genomen.

	#Kick
	while True:
		try:
			kickFilename = input("Drop hier je kick sample: ")
			kick = sa.WaveObject.from_wave_file(kickFilename)
			break
		except FileNotFoundError:
			print("Het pad is niet juist. Probeer het opnieuw")
	print("De kick is succesvol geselecteerd met bestandsnaam: ", kickFilename)
	print("------------------------------------")

	#Snare
	while True:
		try:
			snareFilename = input("Drop hier je snare sample: ")
			snare = sa.WaveObject.from_wave_file(snareFilename)
			break
		except FileNotFoundError:
			print("Het pad is niet juist. Probeer het opnieuw")
	print("De snare is succesvol geselecteerd met bestandsnaam: ", snareFilename)
	print("------------------------------------")

	#Hihat
	while True:
		try:
			hatFilename = input("Drop hier je hihat sample: ")
			hat = sa.WaveObject.from_wave_file(hatFilename)
			break
		except FileNotFoundError:
			print("Het pad is niet juist. Probeer het opnieuw")
	print("De hihat is succesvol geselecteerd met bestandsnaam: ", hatFilename)
	print("------------------------------------")


#deze functie is voornamelijk de gebruikers interface waar de gebruiker mee werkt.
def commandline():
	print("_______________Welkom!______________")
	print("____________Beat Machine____________")
	print("Voor hulp, gebruik het commando Help")
	print("------------------------------------")

	#Vraagt de gebruiker om het aantal bpm
	while True:
		try:
			BPM = int(input("Voor het gewenste beats per minute in: "))
			
			break
		except Exception:
			print("probleem")
	print("U heeft ", BPM, " Bpm ingevuld!")
	print("------------------------------------")

	#vraagt de gebruiker om de maatsoort in te voeren.
	while True:
		maatsoort= input("Vul de gewenste maatsoort in. U kunt kiezen uit: 4/4, 5/4 en 7/4: ")
		if (maatsoort == "4/4" or (maatsoort == "5/4") or (maatsoort == "7/4")):
			break
		else:
			print("Probeer het opnieuw")
	print("U heeft voor de " + maatsoort+ " maatsoort gekozen!")
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

	print("------------------------------------")



	pass



def main():
	bpm = int(input("Voer het aantal bpm in: "))
	bpm = (60/bpm)/4 

	grid = 0
		
	while grid<17:
		grid+=1

		if (grid==1) or (grid==9):
			playKick()
		elif (grid==3) or (grid==7) or (grid==11) or (grid==15):
			playHihat()
		elif (grid==5) or (grid==13):
			playSnare()

		time.sleep(bpm)
	
os.system("clear")
commandline()