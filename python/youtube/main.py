# from apiclient.discovery import build
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow


# youtube = build('youtube', 'v3', developerKey = api_key)

# # print(type(youtube))

# req = youtube.search().list(q = 'avengers', part = 'snippet', type = 'video')

# print(type(req))

# res = req.execute()

# # print(res)


# print("playlist")

# req = youtube.playlists().insert(part = 'snippet', onBehalfOfContentOwner= 'testplaylist')

# res = req.execute()

# print(res)



scopes = ["https://www.googleapis.com/auth/youtube"]


client_secrets_file = "cs.json"


print("here1------------------------------------------")
# Get credentials and create an API client
flow = InstalledAppFlow.from_client_secrets_file(client_secrets_file, scopes)
flow.run_local_server()
credentials = flow.credentials

youtube = build("youtube", "v3", credentials=credentials)
print("here1------------------------------------------")

# request = youtube.playlists().insert(
#     part="snippet",
#     body={
#         "snippet": {
#             "title": "test playlist",
#             "description": "This is a test playlist"
#         }
#     }
# )

request = youtube.playlistItems().insert(
    part="snippet",
    body={
        "snippet": {
            "playlistId" : "PLfLReqs4zJODuyADQ8NE6w_AZLC5DJNZO",
        
            "resourceId" : {
                "kind" : "youtube#video",
                "videoId" : "gyMwXuJrbJQ",
                },
        }
    }
)
response = request.execute()

print(response)
