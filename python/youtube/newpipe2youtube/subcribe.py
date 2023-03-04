import sqlite3
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow


def subscribe(cid, youtube):
    request = youtube.subscriptions().insert(
        part="snippet",
        body={
            "snippet": {
                "resourceId" : {
                    "kind": "youtube#subscription",
                    "channelId": cid,
                    }
            }
        }
    )
    response = request.execute()
    print(f"subscribed to {cid}")

def playlists(cursor, youtube):
    # table_list = [a for a in cursor.execute("SELECT name FROM sqlite_master WHERE type = 'table'")]
    # res = [i for i in cursor.execute("SELECT * FROM streams")]

    res = [i for i in cursor.execute("SELECT * FROM subscriptions")]

    for item in res:

        clink: str = item[2]

        cid = clink.split("channel/",1)[1]

        subscribe(cid, youtube)

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
