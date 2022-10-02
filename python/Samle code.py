# import the random module from the library
from random import randint
# create an empty list of scores to populate with randint
scores = []
# repeat the following code 30 times
for x in range (0, 30):
    # Generate a random number from 0 to 10 and append to scores
    scores.append(randint(0, 10))
# print the generated list of scores
print(scores)
# define the count function with parameters of x and scores
def count(x, scores):
    # initialise total at 0
    total = 0
    #for each score in the scores list
    for score in scores:
        # if the score is equal to x (the user input)
        if score == x:
            # increment the total variable by 1
            total = total+1
    # return the final total to the main program
    return total

# definen the function to count within a given range with the parameters x and scores
def count_within_range(x, scores):
    # initialise total at 0
    total = 0
    # for each score in the scores list
    for score in scores:
        # if the score is less than x (the user input)
        if score < x:
            # increment the total varaible by 1
            total = total+1
    # return that total to the main program
    return total

# define the function to count the vowels in a word with the parameter of word2
def count_vowels(word2):
    # initialise total at 0
    total = 0
    # for every character in the word
    for char in word2:
        # if the character is "a" "e" "i" "o" or "u"
        if char == "a" or char == "e" or char == "i" or char == "o" or char == "u":
            # increment the total variable by 1
            total = total+1
    # return the total to the main program
    return total

# set x to the user input (in this case an integer)
x = int(input("Please enter a number 1-10:"))
# set the total to the returned result from the count function
total = count(x, scores)
# output the result to the user
print("{0} learner/s recieved".format(total), x, "marks")

# set x to the user input (in this case an integer)
x = int (input("Please enter a value to check how many students scored below e.g 5:"))
# set total to the result returned from the count_with_range function
total = count_within_range(x, scores)
# output the result to the user
print ("{0} learner/s recieved".format(total),"less than",x,"marks")

# set word to the user input (in this case a string)
word = input("Please enter a word")
# convert the word to all lowercase
word2 = word.lower()
# set total to the result returned by the count_vowels function
total = count_vowels(word2)
# output the result to the user
print (word, "has",total,"vowel/s")