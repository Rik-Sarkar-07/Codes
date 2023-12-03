import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    speak("Hello Sudipto")
    speak("I am your voice assistant. Please tell me how may I help you ?")


def takeCommand():
    # It takes command via microphone input from the user and returns string output
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print(f"Sudipto said: {query}\n")

    except Exception as e:
        # print(e)
        print("Say that again please...")
        return "None"
    return query


if __name__ == "__main__":
    wishMe()
    while True:
        # if 1:
        query = takeCommand().lower()

        # Logic for executing tasks based on query
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)

        elif 'open youtube' in query:
            webbrowser.open("youtube.com")

        elif 'open google' in query:
            webbrowser.open("google.com")

        elif 'open stackoverflow' in query:
            webbrowser.open("stackoverflow.com")


        elif 'play music' in query:
            music_dir = 'A:\\My Files\\MP3\\song'
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir, songs[0]))

        elif 'the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"Sir, the time is {strTime}")

        elif 'activate vector' in query:
            speak('vector is now activated boss')
            codePath = "C:\\Users\\USER\\OneDrive\\Desktop\\pic.JPG"
            os.startfile(codePath)

        elif 'who i am' in query:
            speak("your name is Sudipto Sarkar")
            speak("Here is your photo")
            codePath = "A:\\My Files\\Picture\\Swamiji.jpg"
            os.startfile(codePath)

        elif 'hi asisstent how are you' in query:
            speak('I am fine, What about you sudipto?')
        elif 'who is my room partner' in query:
            speak('Your room met is Syantan Manna from tarakeswar')

        elif 'open ai chat' in query or 'open ai' in query:
            webbrowser.open("chat.openai.com")

        elif 'shut down asisstent' in query:
            speak("Ok Boss")
            exit(0)

        elif 'close asisstent' in query:
            speak("Ok Boss")
            exit(0)

        elif 'close voice asisstent' in query:
            speak("Ok Boss")
            exit(0)

        elif 'i said close. asisstent' in query:
            speak("Ok Boss")
            exit(0)

        elif 'close' in query:
            speak("Ok Boss")
            exit(0)
