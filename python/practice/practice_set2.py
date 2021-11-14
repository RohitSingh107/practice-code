from random import randint
from functools import reduce

def format_func():
    name = input("Enter Name: ")
    marks = input("Enter Marks: ")
    phone = input("Enter Phone No: ")

    print(f"The name of the student is {name}, his markes are {marks} and phone number is {phone}.")


def vert_table(numb):
    table = [str(numb*i) for i in range(1,11)]
    print("\n".join(table))

def filter_div5(numb):
    return bool(numb % 5 == 0)

def div_by_f():
    nums = [randint(0, 100) for i in range(100)]
    print(nums)
    filtered_list = filter(filter_div5, nums)
    print(list(filtered_list))

def max_num():
    nums = [randint(0, 98) for i in range(100)]
    print(nums)
    maxn = reduce(max,nums)
    print(maxn)


if __name__ == "__main__":
    max_num()