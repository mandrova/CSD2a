import time
import simpleaudio as sa
import random
import sys
from sys import stdin
import _thread

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
int rand(int procent):
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
def createGrid(string beat):
	if (beat == "4/4"):
		gridSize=16
		kickAccent=[100,0,40,20,0,0,20,0,20,0,80,20,0,0,0,0]
		snareAccent=[0,0,0,0,100,0,0,60,0,0,80,0,0,100,0,20,40]
	elif (beat == "5/4")
		gridSize=20
		accenten=[2,0,0,1,0,2,0,0,1,0,2,0,0,1,0,2,0,0,1,0]
	elif (beat == "7/4")
		gridSize=28
		accenten=[2,0,0,1,0,0,1,0,2,0,0,1,0,0,1,0,2,0,0,1,0,0,1,0,2,0,0,1,0,0,1,0]

#Hier worden de afspeel lijsten gegenereerd.
#Dit gebeurd aan de hand van de lijsten die bij createGrid zijn gegenereerd
def createPlaylists():
	gridNum=0
	while gridNum<gridSize+1:
		accent = kickAccent[gridNum]
		if (gridNum==3) and (kickPlayList[2]>0)
			kickPlayList[3]=0
		elif (gridNum==11) and (kickPlayList[10]>0)
			kickPlayList[11]=0
		else
			kickPlayList[gridNum]=rand(accent)

		accent = snareAccent[gridNum]
		snarePlayList[gridNum]=rand(accent)

		gridNum += 1


#de commandline luisterd op de achtergrond altijd naar bepaalde commandos
#zo kan de gebruiker kiezen om bepaalde dingen uit te voeren terwijl bijv. de beat speelt.
def commandListener()
	userInput = sys.stdin.read(8)
	if (userInput=="play"):

	elif (userInput=="stop")

	elif (userInput=="new")

	elif (userInput=="help")
		print("-----------------Help------------------")
		print("---------------------------------------")
		print("|play------Afspelen van de beat-------|")
		print("|stop------Stoppen van de beat--------|")
		print("|new-------Genereer nieuwe beat-------|")
		print("|exit------Sluit Beatmachine af-------|")
		print("---------------------------------------")
		print("---------------------------------------")



#deze functie is voornamelijk de gebruikers interface waar de gebruiker mee werkt.
def commandline():
	print("______________Welkom!______________")
	print("___________Beat Machine____________")
	print("Voor hulp, gebruik het commando Help")
	print("-----------------------------------")
	BPM = input("Voor het gewenste beats per minute in: ")
	print("U heeft " + BPM + " Bpm ingevuld!")
	print("-----------------------------------")
	maatsoort= input("Vul de gewenste maatsoort in. U kunt kiezen uit: 4/4, 5/4 en 7/4")
	print("U heeft voor de " + maatsoort+ " maatsoort gekozen!")
	print("-----------------------------------")

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
	

main()