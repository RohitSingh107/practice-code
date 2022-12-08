from collections import Counter
import heapq
import itertools
import operator
import time

def fib():
   a, b = 0, 1
   while 1:
      yield a
      a, b = b, a+b


for i in fib():
    print(i)
    if i == 701408733:
        break

fib_gen = fib()
for i in range(10):
    print(next(fib_gen))

# input_list=list(map(int, input("enter numbers: ").split()))

arr = [1, 3, 4, 1, 2, 1, 1, 3, 4, 3, 5, 1, 2, 5, 3, 4, 5]
counter = Counter(arr)
top_three = counter.most_common(3)

print(top_three)

grades = [110, 25, 38, 49, 20, 95, 33, 87, 80, 90]
print(heapq.nlargest(3, grades))
print(heapq.nsmallest(4, grades))



# Python code to apply a function on a list
income = [10, 30, 75]
 
def double_money(dollars):
    return dollars * 2
 
new_income = list(map(double_money, income))
print(new_income)


lst = ["Geeks", "for", "Geeks"]
string = '@'.join(lst)
print(string)


val = [('first', 3, 9), ('second', 4, 6), ('third', 2, 3)]
val.sort(key = lambda x: x[2], reverse=False)
print(val)


dic = [(str(i)+" element", i*2) for i in range(5)]
print(dict(dic))

print(list(filter(lambda x: x%2, range(15))))


n = 16
result = 15 < n < 20
print(result)


l1 = [1, 2, 3]
l2 = [2, 3, 4]
t1 = time.time()
res = map(operator.mul, l1,l2)
t2 = time.time()
print(list(res))
print("Time taken: %.6f seconds" %(t2-t1))


# Python program to demonstrate
# infinite iterators
# for in loop
for i in itertools.count(7, 5):
    if i == 37:
        break
    else:
        print(i, end =" ")


count = 0
# for in loop
for i in itertools.cycle('AB'):
    if count > 7:
        break
    else:
        print(i, end = " ")
        count += 1


# Python code to demonstrate the working of repeat() 
# using repeat() to repeatedly print number 
print ("Printing the numbers repeatedly : ") 
print (list(itertools.repeat(25, 4)))

print("The cartesian product using repeat:")
print(list(itertools.product([1, 2], repeat = 2)))
print()
   
print("The cartesian product of the containers:")
print(list(itertools.product(['geeks', 'for', 'geeks'], '2')))
print()
   
print("The cartesian product of the containers:")
print(list(itertools.product('AB', [3, 4])))
print()


perms = list(itertools.permutations(["a","b","c"], 3))
combs = list(itertools.combinations("abc", 2))
print(perms)
print(combs)
print()

print ("All the permutations of the given list is:") 
print (list(itertools.permutations([1, 'geeks'], 2)))
print()
 
print ("All the permutations of the given string is:") 
print (list(itertools.permutations('AB')))
print()
   
print ("All the permutations of the given container is:") 
print(list(itertools.permutations(range(3), 2)))
print()

print ("All the combination of list in sorted order(without replacement) is:") 
print(list(itertools.combinations(['A', 2], 2)))
print()
   
print ("All the combination of string in sorted order(without replacement) is:")
print(list(itertools.combinations('AB', 2)))
print()
   
print ("All the combination of list in sorted order(without replacement) is:")
print(list(itertools.combinations(range(2), 1)))
print()

print ("All the combination of string in sorted order(with replacement) is:")
print(list(itertools.combinations_with_replacement("AB", 2)))
print()
   
print ("All the combination of list in sorted order(with replacement) is:")
print(list(itertools.combinations_with_replacement([1, 2], 2)))
print()
   
print ("All the combination of container in sorted order(with replacement) is:")
print(list(itertools.combinations_with_replacement(range(2), 1)))
print()



# initializing list 1
li1 = [1, 4, 5, 7]
   
# using accumulate()
# prints the successive summation of elements
print ("The sum after each iteration is : ", end ="")
print (list(itertools.accumulate(li1)))
print()
   
# using accumulate()
# prints the successive multiplication of elements
print ("The product after each iteration is : ", end ="")
print (list(itertools.accumulate(li1, operator.mul)))
print()
   

# initializing list 1
li1 = [1, 4, 5, 7]
   
# initializing list 2
li2 = [1, 6, 5, 9]
   
# initializing list 3
li3 = [8, 10, 5, 4]
 
# using chain() to print all elements of lists
print("All values in mentioned chain are : ", end ="")
print(list(itertools.chain(li1, li2, li3)))
print()

list_of_lists = [[1, 2], [3, 4]]
chain_object = itertools.chain.from_iterable(list_of_lists)
# Return chain object with nested lists separated
# Convert to list to flatten
flattened_list = list(chain_object)
print(flattened_list)
print()

# using compress() selectively print data values
print ("The compressed values in string are : ", end ="")
print (list(itertools.compress('GEEKSFORGEEKS', [1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0])))
print()

# initializing list 
li = [2, 4, 5, 7, 8]
   
# using dropwhile() to start displaying after condition is false
print ("The values after condition returns false : ", end ="")
print (list(itertools.dropwhile(lambda x : x % 2 == 0, li)))
print()


# initializing list 
li = [2, 4, 5, 7, 8]
 
# using filterfalse() to print false values
print ("The values that return false to function are : ", end ="")
print (list(itertools.filterfalse(lambda x : x % 2 == 0, li)))
print()


# initializing list 
li = [2, 4, 5, 7, 8, 10, 20]
     
# using islice() to slice the list acc. to need
# starts printing from 2nd index till 6th skipping 2
print ("The sliced list values are : ", end ="")
print (list(itertools.islice(li, 1, 6, 2)))
print()

# initializing tuple list
li = [ (1, 10, 5), (8, 4, 1), (5, 4, 9), (11, 10, 1) ]
   
# using starmap() for selection value acc. to function
# selects min of all tuple values
print ("The values acc. to function are : ", end ="")
print (list(itertools.starmap(min, li)))
print()

# initializing list 
li = [2, 4, 6, 7, 8, 10, 20]
   
# using takewhile() to print values till condition is false.
print ("The list values till 1st false value are : ", end ="")
print (list(itertools.takewhile(lambda x : x % 2 == 0, li )))
print()

   
# initializing list 
li = [2, 4, 6, 7, 8, 10, 20]
   
# storing list in iterator
iti = iter(li) 
   
# using tee() to make a list of iterators
# makes list of 3 iterators having same values.
it = itertools.tee(iti, 3)
   
# printing the values of iterators
print ("The iterators are : ")
for i in range (0, 3):
    print (list(it[i]))
print()

# using zip_longest() to combine two iterables.
print ("The combined values of iterables is  : ")
print (*(itertools.zip_longest('GesoGes', 'ekfrek', fillvalue ='_' )))
print()


print ("Pairwise grouping  : ")
print(list(itertools.pairwise("ABCDEF")))
print()

print ("groupby()  : ")
print(list(itertools.groupby("AAABBACCC")))
print()
