with open('food.csv', 'r') as f:
    data = f.read()
    print(data)

with open('food.csv','a') as f:
    f.write('name' + ',' + 'food' + '\n')
    