from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
import sqlite3

def getSQLiteConnection():
    con = sqlite3.connect("newpipe.db")
    cur = con.cursor()
    return cur

def getYoutube():

    scopes = ["https://www.googleapis.com/auth/youtube"]

    client_secrets_file = "cs.json"

# Get credentials and create an API client
    flow = InstalledAppFlow.from_client_secrets_file(client_secrets_file, scopes)
    flow.run_local_server()
    credentials = flow.credentials

    youtube = build("youtube", "v3", credentials=credentials)   

    return youtube

def main():
    pass

if __name__ == "__main__":
    main()
