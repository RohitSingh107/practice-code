
from get_setup import getSQLiteConnection, getYoutube


def createPlaylist(pname, youtube):
    req = youtube.playlists().insert(
        part="snippet,status",
        body={
            "snippet": {
                "title": pname,

            },
            "status": {
                "privacyStatus": "private"
            },
        }
    )
    res = req.execute()
    print(f"created playlist {pname}")


def createPlaylists(cursor, youtube):
    res = [i for i in cursor.execute("SELECT * FROM playlists")]

    for item in res:
        pname = item[1]
        createPlaylist(pname, youtube)


def main():

    cur = getSQLiteConnection()

    youtube = getYoutube()

    createPlaylists(cur, youtube)


if __name__ == '__main__':
    main()
