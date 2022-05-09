with open('highscore.txt','r') as f:
    highscore = f.read()
    highscore = int(highscore)
score = 0
while True:

    print('Welcome to maths game')
    print('can you answer 5 questions to highscore')
    print('(Q1) 2 x 2 x 2 = ?')
     
    answer = int(input('your answer: '))
    if answer == 8:
        print('Correct!')
        score =score+1
    else:
        print('Wrong!')
    print('Your Score is ',score )
    print('Highscore is ' , highscore)
    
    print('(Q2) 5 x 4 = ?')
    
    answer2 = int(input('your answer: '))
    if answer2 == 20:
        print('Correct!')
        score =score+1
    else:
        print('Wrong!')
    print('Your Score is ',score )
    
    if score >= highscore:
        highscore = score
        with open('highscore.txt', 'w') as f:
            f.write(str(highscore))
        print('You made a new Highscore!')
    print('Highscore is ', highscore)
    
    
     