import requests


chunk_size = 256 # bytes

url = "https://dms.licdn.com/playlist/vid/C4D0DAQHD9Pwz9fYkFg/learning-original-video-vbr-540/0/1679444766225?e=1692687600&v=beta&t=B7SMqD1wVJNDIi6vxYzAH9Kl8MlwIrsKtnkzHDmh7UM#.mp4"

print("Sending request")
r = requests.get(url=url, stream=True)
print("request sent")

with open('lynda.mp4', "wb") as f:
    for chunk in r.iter_content(chunk_size=chunk_size):
        f.write(chunk)
