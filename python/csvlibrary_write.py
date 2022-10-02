import csv

name ='Pam'

food = 'Egg'

with open('food.csv', mode ='a') as file:
    fav =csv.writer(file, delimiter = ',')
    fav.writerow([name,food])