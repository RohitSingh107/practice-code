from functools import reduce

# Functional programming

def func():
    def print_func():
        print("Ok")
    return print_func

func()()

myreverse = lambda x : x[::-1]

def func_app(funcn, string):
    return funcn(string)

# print(func_app(myreverse, "This is text"))

# print((lambda x, y : (x+y, x*y, x/y, x**y))(4,7))

map_object = map(lambda x : x[::-1], ["me", "Vool", "Frool", "cup", "MoonooM"])
# print(map_object)
# for i in map_object:
    # print(i)

# print("$".join(list(map(str,[4,5,8,35,79,51]))))

# print(list(map((lambda x, y, z : x + y + z), [1,2,3], [10,20,30], [100,200,300])))

# print(list(filter(lambda x: x > 100, [1, 101, 2, 2225, 3, 3343])))

# print(list(filter(lambda x : x % 2 == 0, range(20))))

print(reduce(lambda x, y : x if x > y else y, [4,2,5,7,1,48]))