def factorial(num):
    if num == 1:
        return 1
    elif num == 0:
        return 1
    else:
        num = num * factorial(num - 1)
    return num

print(factorial(9))

def fibonacci(num):
    if num == 1:
        return 1
    elif num == 0:
        return 0
    else:
        num = fibonacci(num-1) + fibonacci(num-2)

    return num


print(fibonacci(8))