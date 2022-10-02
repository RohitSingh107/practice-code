import requests
r = requests.get("https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY")
NASA = r.json()
print(NASA)