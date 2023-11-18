from icecream import ic

def myf(a, b):
    for i in range(10):
        if a == b:
            ic()
        else:
            if i % 2 == 0:
                ic()
            else:
                ic()


def add(x, y):
    return x + y


ic(add(x=10, y=53))
ic(add(x=30, y=40))
ic(add(x=60, y=26))
ic(add(x=60, y=20))
r = ic(add(x=90, y=29))
print(r)

test_dict = {
    "Gfg": {"a": [1, 5, 6, 7], "b": [6, 7, 8, 9]},
    "is": {"best": [2, 8, 9, 0]},
}
ic(test_dict["Gfg"]["b"][2])
ic(test_dict)


print(myf(4, 2))
