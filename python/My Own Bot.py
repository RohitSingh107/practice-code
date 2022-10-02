print("I am Rohit")
print('I am a comuter programmer')
print('It is cool')
my_name = 'Rohit Singh'
print("my name is " + my_name)
#print('please enter your neme')
#user_name = input('your name: ')
#print("Hello " + user_name + ' , Welcome to Pyton')
print('let\'s do some calculations')
print("Choose from the list:")
print('1. Addition')
print('2. Subtraction')
print('3. Multiplication')
print('4. Division')
print('5. Area of circle')
print('6. Area of rectangle')
print('7. Average')
command = input('Choose your required operation: ')
if command == '1':
    input1 = input('Enter the number: ')
    input2 = input('Enter the number: ')
    result1 = float(input1) + float(input2)
    print(input1 + '+' + input2 + '=' + str(result1))
elif command == '2':
    input3 = input('Enter the number: ')
    input4 = input('Enter the number: ')
    result2 = float(input3) - float(input4)
    print(input3 + '-' + input4 + '=' + str(result2))
elif command == '3':
    input8 = input('Enter the number: ')
    input9 = input('Enter the number: ')
    result5 = float(input8)*(float(input9))
    print(input8 + 'X' + input9 + '=' + str(result5))
elif command == '4':
    input10 = input('Enter the number: ')
    input11 = input('Enter the number: ')
    result6 = float(input10)/(float(input11))
    print(input10 + '/' + input11 + '=' + str(result6))
elif command == '5':
    input5 = input('Enter the radius of circle: ')
    result3 = float(3.14)*float(input5)*float(input5)
    print('3.14' + 'X' + input5 + 'X' + input5 + '=' + str(result3))
elif command == '6':
    input6 = input('Enter the Length of Rectangle: ')
    input7 = input('Enter the Breadth of Rectangle: ')
    result4 = float(input6)*float(input7)
    print(input6 + 'X' + input7 + '=' + str(result4))
elif command == '7':
    input12 = input('how many numbers: ')
    total = 0
    for number_count in range(int(input12)):
        number = input('Enter the Number' + str(int(number_count)+1) + ':')
        total = total + float(number)
    result = total/float(input12)
    print('the average =' + str(result))
else:
    print('Sorry' + ',' + 'Please choose correct command from the list')