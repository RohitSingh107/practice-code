import csv
with open('food.csv') as f:
    fav = csv.reader(f, delimiter =',')
    for row in fav:
        print(row)