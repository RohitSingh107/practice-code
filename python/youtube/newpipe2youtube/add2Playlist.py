
from get_setup import getSQLiteConnection, getYoutube


def getPlaylisRecord(cursor):
    playlists = [i for i in cursor.execute("SELECT * FROM playlists")]
    playlist_record = {}
    for i in playlists:
        playlist_record[i[0]] = i[1]

    return playlist_record


def getStreamRecord(cursor):
    streams = [i for i in cursor.execute("SELECT * FROM streams")]
    streams_record = {}
    for i in streams:
        vlink = i[2]
        try:
            streams_record[i[0]] = vlink.split("watch?v=", 1)[1]
        except:
            print(f"Not added i = {i}\n\n")

    print(len(streams_record))
    return streams_record

def createPlaylist(pid, vid, youtube):
    req = youtube.playlistItems().insert(
        part="snippet",
        body={
            "snippet": {


            },
        }
    )
    res = req.execute()



def createPlaylists(cursor):
    playlist_stream_join = [i for i in cursor.execute(
        "SELECT * FROM playlist_stream_join")]

    ## Need id instead of name
    playlistId2Name = getPlaylisRecord(cursor)
    streamId2VideoId = getStreamRecord(cursor)

    for j in playlist_stream_join:
        print(f"{streamId2VideoId[j[1]]} : {playlistId2Name[j[0]]}\n")

    print(
        f"Total editions: {len([(streamId2VideoId[j[1]], playlistId2Name[j[0]]) for j in playlist_stream_join])}")



def main():

    cur = getSQLiteConnection()

    # youtube = getYoutube()

    createPlaylists(cur)


if __name__ == '__main__':
    main()
