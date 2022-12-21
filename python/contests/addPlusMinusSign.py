
def main():
    t = int(input())
    while t != 0:
        n = int(input())
        s = input()

        ans = ""
        track = s[0]
        for i in range(1,n):
            if track == '0':
                ans += '+'
                track = s[i]
            else:
                if s[i] == '0':
                    ans += '+'
                else:
                    ans += '-'
                    track = '0'
        

            # if s[i-1] == '0':
            #     ans += '+'
            # else:
            #     if s[i] == '0':
            #         ans += '+'
            #     else:
            #         ans += '-'
        print(ans)

        t -=1


main()

