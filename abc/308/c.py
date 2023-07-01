import numpy as np

def main():
    N = int(input())
    AB = [list(map(int, input().split())) for _ in range(N)]
    # print(N, AB)

    P = []
    for ab in AB:
        P.append(ab[0]/(ab[0]+ab[1]))

    # print(P)

    P_np = np.array(P)
    ans = np.argsort(-P_np)
    # for a in ans:
    #     print(a+1)

    print(*ans+1)

if __name__ == '__main__':
    main()

'''
in
3
1 3
3 1
2 2
out
2 3 1

in
2
1 3
2 6
out
1 2

in
4
999999999 1000000000
333333333 999999999
1000000000 999999997
999999998 1000000000
out
3 1 4 2

'''