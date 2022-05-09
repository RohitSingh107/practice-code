#-----------------------------------------------------------------------

def randomRead():

    try:
        select_sql = "select * from computer order by random() limit 1;"
        result = conn.execute(select_sql)
        return result.fetchone()
    except Exception as e:
        print('DB read exception: %s' % e)
        return "Read fail"

#-----------------------------------------------------------------------

import sqlite3

conn = sqlite3.connect("computer_cards.db")

print(randomRead())

conn.close()