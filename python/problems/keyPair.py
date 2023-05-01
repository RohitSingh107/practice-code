
def hasArrayTwoCandidates(arr, n, x):
    ar = sorted(arr)

    l = 0
    h = n-1

    while l < h:

        if ar[l] + ar[h] < x:
            l += 1
        elif ar[l] + ar[h] > x:
            h -= 1
        else:
            return True
     
    return False

















def main():
    arr = [1, 2, 4, 3, 6]
    x = 10
    n = 5
    print(f"ans is {hasArrayTwoCandidates(arr, n, x)}")

if __name__ == '__main__':
    main()
