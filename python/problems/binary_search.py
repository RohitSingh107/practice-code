from typing import List

def lowerBound(l : List[int], n : int) -> int:
    if n < l[0]:
        return 0
    size : int = len(l)
    lo : int = 0
    hi : int = size - 1

    while hi > lo:
        mid : int = (lo + hi)//2

        if l[mid] >= n:
            hi = mid 
        else:
            lo = mid + 1
        
          
    if lo < size and l[lo] < n:
        lo += 1



    return lo


def upperBound(l : List[int], n : int) -> int:
    if n < l[0]:
        return 0

    size : int = len(l)
    lo : int = 0
    hi : int = size - 1

    while hi > lo:
        mid : int = (lo + hi)//2
        print(f"h is {hi}, lo is {lo}")
        print(mid)

        if l[mid] <= n:
            lo = mid + 1
        else:
            hi = mid 
        
    if lo < size and l[lo] <= n:
        lo += 1

    return lo


def main():
    l = [-100000000000, 5, 100000000000, 100000000000, 100000000000, 100000000000, 100000000000, 100000000000, 100000000000]
    n = 8
    print(upperBound(l, n))

if __name__ == '__main__':
    main()


