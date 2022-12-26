import openai
import pyttsx3
import speech_recognition as sr
import webbrowser
import os
import datetime

openai.api_key = "< Enter your won API Key >"

completion = openai.Completion()


def Reply(qs):
    prompt = f'Sudipta: {qs}\n Virtual Assistant : '
    response = completion.create(prompt=prompt, engine="text-davinci-002", stop=['\Sudipta'], max_tokens=200)
    ans = response.choices[0].text.strip()
    return ans


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)


def speak(text):
    engine.say(text)
    engine.runAndWait()


def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print('Listening...')
        r.pause_threshold = 1
        audio = r.listen(source)
    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print("Sudipta Said: {} \n".format(query))
    except Exception as e:
        print("Say Again...")
        return "None"
    return query


if __name__ == '__main__':
    print("Virtual Assistant Running...")
    speak("Hello Sudipto, I am Your Virtual Assistant. Ask Me Any Question")

    while True:
        query = takeCommand().lower()
        if 'open youtube' in query:
            webbrowser.open("www.youtube.com")
        elif 'open google' in query:
            webbrowser.open("www.google.com")

        elif 'open stackoverflow' in query:
            webbrowser.open("stackoverflow.com")


        elif 'play music' in query:
            music_dir = 'A:\\My Files\\MP3\\song'
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir, songs[0]))

        elif 'the time' in query or 'what is the time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"Sudipta Sir, the time is {strTime}")

        elif 'who i am' in query:
            speak("your name is Sudipta Sarkar")
            speak("Here is your photo")
            codePath = "A:\\My Files\\Picture\\Swamiji.jpg"
            os.startfile(codePath)

        elif 'hi assistent how are you' in query:
            speak('I am fine, What about you sudipto?')
        elif 'bye' in query or 'close' in query or 'stop' in query:
            speak("Good Bye Sudipta, Thank you.")
            break

        # Take Question and get answer via Open AI
        ans = Reply(query)
        print(ans)
        speak(ans)

