import sqlite3
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow


def addPlaylist(pid, youtube):
    # Wrong function
    request = youtube.subscriptions().insert(
        part="snippet",
        body={
            "snippet": {
                "resourceId" : {
                    "kind": "youtube#subscription",
                    "channelId": pid,
                    }
            }
        }
    )
    response = request.execute()
    print(response)
    print("\n")
    print("\n")
    print("\n")

def playlists(cursor, youtube):
    # table_list = [a for a in cursor.execute("SELECT name FROM sqlite_master WHERE type = 'table'")]
    # res = [i for i in cursor.execute("SELECT * FROM streams")]

    tes = [i for i in cursor.execute("SELECT * FROM remote_playlists")]

    for item in tes[15:20]:

        plink: str = item[3]

        pid = plink.split("playlist?list=",1)[1]

        addPlaylist(pid, youtube)

        # print(pid)

    
    # print(tes[10:15])

def main():
    con = sqlite3.connect("newpipe.db")
    cur = con.cursor()
    scopes = ["https://www.googleapis.com/auth/youtube"]

    client_secrets_file = "cs.json"

    print("here1------------------------------------------")
# Get credentials and create an API client
    flow = InstalledAppFlow.from_client_secrets_file(client_secrets_file, scopes)
    flow.run_local_server()
    credentials = flow.credentials

    youtube = build("youtube", "v3", credentials=credentials)

    playlists(cur, youtube)


if __name__ == "__main__":
    main()
