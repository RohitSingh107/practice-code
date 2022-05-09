import sqlite3
conn = sqlite3.connect("computer_cards.db")


def create(name, cores):
    insert_sql = "INSERT INTO computer(name, cores) VALUES ('{}', {})".format(name, cores)

    conn.execute(insert_sql)

    conn.commit()
create("My computer", 4)
print("Enter the details:")

name = input("Name > ")
cores = input("Cores > ")

create(name, cores)

conn.close()