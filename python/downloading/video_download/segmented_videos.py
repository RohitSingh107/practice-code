import requests
import m3u8
from pprint import pprint
import subprocess


# master_m3u8_url = "https://manifest.prod.boltdns.net/manifest/v1/hls/v4/clear/3588749423001/5126bb67-06ff-45f7-bb09-961de116d67f/10s/master.m3u8?fastly_token=NjRkYjZiNjRfYmVkZWJjZWEyNzgwNjE4YzhjOWEyM2NjZWZkMzk3N2QwYzc2NTNjM2M0N2EzZDZkYzUwMzM5MTU5OTcyOTI3Nw=="
# master_m3u8_url = "https://manifest.prod.boltdns.net/manifest/v1/hls/v4/clear/3588749423001/5d55d3e7-ef4a-4f36-b7fc-3e4b1dcd030e/10s/master.m3u8?fastly_token=njrkyjlinzdfnjlhogi2njlhn2jmntdhotizmjhkyjbkodfkogq2mda1ymm3zddkmjnjzdvjn2zkzju4mtvmodlkmznjzjjjng=="
master_m3u8_url = "	https://manifest.prod.boltdns.net/manifest/v1/hls/v4/clear/3588749423001/b381fe79-6059-48bd-95eb-7ad33a0d951e/10s/master.m3u8?fastly_token=NjRkYmI1MTlfMzhhOTg0ZjAwYTQ3MjlkNjIxYWUzM2Y1ODBhMjQ4MDdkMTVhNzkxZjdkNmFlZDlhY2UxZWE0NzQ1ZjliNzk2ZQ=="

r = requests.get(master_m3u8_url)

# pprint(r.text)

m3u8_master = m3u8.loads(r.text)

# pprint(m3u8_master.data['playlists'])
video_playlist_url = m3u8_master.data['playlists'][0]['uri'] # Video # Here Video resolution can be selected according to index
audio_medias_url = m3u8_master.data['media'][0]['uri'] # Audio # Here Audio can be selected according to index

rv = requests.get(video_playlist_url)
ra = requests.get(audio_medias_url)

# print(r.text)
video_playlist = m3u8.loads(rv.text)
audio_medias = m3u8.loads(ra.text)
# pprint(playlist.data['segments'][0]['uri']) # First segment url

print("Downloading all video segments...")
i = 0
with open('ipl.ts', 'wb') as f:
    for segment in video_playlist.data['segments']:
        print(f"Downloading video segment no. {i}")
        uri = segment['uri']
        r = requests.get(uri)
        f.write(r.content)
        i += 1
print("Video Download Complete")

print("Downloading all audio segments...")
i = 0
with open('ipl_audio.ts', 'wb') as f:
    for segment in audio_medias.data['segments']:
        print(f"Downloading audio segment no. {i}")
        uri = segment['uri']
        r = requests.get(uri)
        f.write(r.content)
        i += 1
print("Audio Download Complete")

print("Coverting video to mp4")
subprocess.run(['ffmpeg', '-i', 'ipl.ts', 'ipl.mp4'])

print("Merging Audio and video")
subprocess.run(['ffmpeg', '-i', 'ipl.mp4', '-i', 'ipl_audio.ts', '-c:v', 'copy', '-c:a', 'aac', 'output.mp4'])
