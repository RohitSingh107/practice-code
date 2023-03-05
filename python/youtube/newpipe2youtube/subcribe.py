# from . import get_setup
from get_setup import getYoutube, getSQLiteConnection


def subscribe(cid, youtube):
    req = youtube.subscriptions().insert(
        part="snippet",
        body={
            "snippet": {
                "resourceId": {
                    "kind": "youtube#subscription",
                    "channelId": cid,
                }
            }
        }
    )
    res = req.execute()
    print(f"subscribed to {cid}")


def subscribeChannels(cursor, youtube):
    # table_list = [a for a in cursor.execute("SELECT name FROM sqlite_master WHERE type = 'table'")]
    # res = [i for i in cursor.execute("SELECT * FROM streams")]

    res = [i for i in cursor.execute("SELECT * FROM subscriptions")]

    for item in res:

        clink: str = item[2]

        cid = clink.split("channel/", 1)[1]

        subscribe(cid, youtube)


def main():
    # con = sqlite3.connect("newpipe.db")
    cur = getSQLiteConnection()
    youtube = getYoutube()

    subscribeChannels(cur, youtube)


if __name__ == "__main__":
    main()
