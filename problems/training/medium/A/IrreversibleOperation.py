'''https://atcoder.jp/contests/agc029/tasks/agc029_a'''

def main():
    S = list(input())
    N = len(S)

    count = 0
    flag_b = True
    flag_w = False
    for s in S:
        if s == 'B' and flag_b:
            flag_b = False
            flag_w = True
            c = 1
        elif s == 'W' and flag_w:
            count += c
        elif flag_w:
            c += 1
    print(count)

    # count = 0
    # while True:
    #     flag = True
    #     i = 0
    #     while i+1 < N:
    #         if S[i] == 'B' and S[i+1] == 'W':
    #             flag = False
    #             S[i] = 'W'
    #             S[i+1] = 'B'
    #             count += 1
    #         i += 1
    #     if flag:
    #         break

    # print(count)

if __name__ == '__main__':
    main()