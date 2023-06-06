
def hasArrayTwoCandidates(arr, n, x):

    s = set()

    for i in arr:
        if (x - i) in s:
            # print(f"i is {i}, x - i is {x -i}")
            return True
        s.add(i)
    return False

















def main():
    # arr = [1, 2, 4, 3, 6]
    # x = 10
    # n = 5
    # arr = [1, 4, 45, 6, 10, 8]
    # x = 16
    # n = 6
    arr = [1, 2, 5, 6, 7]
    n = 5
    x = 4
    print(f"ans is {hasArrayTwoCandidates(arr, n, x)}")

if __name__ == '__main__':
    main()
