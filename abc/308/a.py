def main():
    S = list(map(int, input().split()))
    # print(S)

    ans = 'Yes'
    for i in range(len(S)-1):
        if S[i] <= S[i+1]:
            if S[i] < 100 or S[i+1] > 675 or S[i] % 25 != 0 or S[i+1] % 25 != 0:
                ans = 'No'
                break
            continue
        else:
            ans = 'No'
            break

    print(ans)

if __name__ == '__main__':
    main()

'''
in
125 175 250 300 400 525 600 650
out
Yes

in
100 250 300 400 325 575 625 675
out
No

in
0 23 24 145 301 413 631 632


'''