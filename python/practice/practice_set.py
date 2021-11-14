# CH12 Practice set Code With Harry
from random import randint

def open_files(file_name):
    try:
        with open(file_name, "r") as f:
            print(f.read(), "\n")

    except FileNotFoundError as e:
        print(f"file named {file_name} is not found")
        print(e, "\n")


def pick_element():
    lis = [randint(0,99) for i in range(10)]
    print(lis)
    for i, e in enumerate(lis):
        if i == 2 or i == 4 or i == 6:
            print(f"{i + 1}th element is {e}")

def multiplication_table():
    num = int(input("Enter the number: "))
    return [num*table for table in range(1,11)]

def write_table():

    table = str(multiplication_table())
    with open("table.txt", "a") as f:
        f.write(table)
        f.write("\n")
    print(table)

def mydivision():

    fir_num = int(input("Fisrt Num: "))
    sec_num = int(input("Second Num: "))

    try:
        print(fir_num/sec_num)

    except ZeroDivisionError:
        print("Infinite")


def main():
    write_table()

if __name__ == "__main__":
    main()
