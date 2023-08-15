#!/usr/bin/env python
# coding: utf-8

# In[1]:


import requests
import json
from bs4 import BeautifulSoup
import m3u8
import subprocess


# In[2]:


SNAP_URL = 'https://t.snapchat.com/OYiAEPSl'
OUTPUT_NAME = 'mysnap'
chunk_size = 256


# In[3]:


r = requests.get(SNAP_URL)


# In[4]:


soup = BeautifulSoup(r.text, 'html.parser')


# In[5]:


script_tag = soup.find("script", {"id": "__NEXT_DATA__"})


# In[6]:


snap_data = json.loads(script_tag.string)


# In[7]:


master_m3u8_url = snap_data['props']['pageProps']['preselectedStory']['premiumStory']['playerStory']['snapList'][0]['snapUrls']['mediaUrl']


# In[8]:


r = requests.get(master_m3u8_url)


# In[9]:


master_m3u8 = m3u8.loads(r.text)


# In[10]:


video_m3u8_url = 'https://cf-st.sc-cdn.net/d/' + master_m3u8.data['playlists'][-1]['uri']


# In[11]:


audio_m3u8_url = 'https://cf-st.sc-cdn.net/d/' + master_m3u8.data['media'][-1]['uri']


# In[12]:


rv = requests.get(video_m3u8_url)
ra = requests.get(audio_m3u8_url)


# In[13]:


video_m3u8 = m3u8.loads(rv.text)
audio_m3u8 = m3u8.loads(ra.text)


# In[14]:


video_url = 'https://cf-st.sc-cdn.net/d/' + video_m3u8.data['segment_map'][0]['uri']
audio_url = 'https://cf-st.sc-cdn.net/d/' + audio_m3u8.data['segment_map'][0]['uri']


# In[15]:


video_url


# In[16]:


r = requests.get(url=video_url, stream=True)
with open(f"{OUTPUT_NAME}-video.mp4", "wb") as f:
    for chunk in r.iter_content(chunk_size=chunk_size):
        f.write(chunk)


# In[17]:


r = requests.get(url=audio_url, stream=True)
with open(f"{OUTPUT_NAME}-audio.mp4", "wb") as f:
    for chunk in r.iter_content(chunk_size=chunk_size):
        f.write(chunk)


# In[18]:


subprocess.run(['ffmpeg', '-i', f"{OUTPUT_NAME}-video.mp4", '-i', f"{OUTPUT_NAME}-audio.mp4", '-c:v', 'copy', '-c:a', 'aac', f"{OUTPUT_NAME}.mp4"])

