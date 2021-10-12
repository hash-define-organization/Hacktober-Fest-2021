import speech_recognition as sr
import pyttsx3
import pywhatkit
import datetime
import wikipedia
import pyjokes

def talk(text):
    engine.say(text)
    engine.runAndWait()

listener = sr.Recognizer()
engine=pyttsx3.init()
voices=engine.getProperty('voices')    #this and the next statements are changing male voice to female voice
engine.setProperty('voice',voices[1].id)
engine.say('I am your alexa')
engine.say('what can i do for you')
engine.runAndWait()
def take_command():
    try:
        with sr.Microphone() as source:
            print('listening...')
            voice = listener.listen(source)
            command = listener.recognize_google(voice)
            command=command.lower()
            if 'alexa' in command:
                command=command.replace('alexa','')  # in this line we are removing word alexa from the string
                print(command)
    except:
        pass
    return command

def run_alexa():
    command = take_command()
    print(command)
    if 'play' in command:
        song = command.replace('play', '')
        talk('playing' + song)
        # talk('playing' + song)
        print('playing...')
        pywhatkit.playonyt(song)
    elif 'time' in command:
        time=datetime.datetime.now().strftime('%I:%M %p')  #it is converting 24 hour clock
        print(time)
        talk('current time is' + time)
    elif 'who is' in command:
        person=command.replace('who is','')
        information=wikipedia.summary(person,4)   #this 4 is telling us the number of lines we want alexa to read
        print(information)
        talk(information)
    elif 'language' in command:
        talk('I speak English language')
    elif 'where do you live' in command:
        talk('I live inside your machine')
    elif 'sleep' in command:
        talk('I hope you had a good day! good night. sweet dreams. see you tommorow')
    elif 'joke' in command:
        print(pyjokes.get_joke())
        talk(pyjokes.get_joke())
    elif 'date' in command:
        talk('yes! but you will have to come inside your machine to meet me! haha')
    else:
        talk('Sorry! Can you please repeat?')

while True:
    run_alexa()
