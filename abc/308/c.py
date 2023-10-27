import numpy as np
from functools import cmp_to_key

def ans_key(a, b):
    x, y, i = a
    xx, yy, ii = b
    s = x * yy - xx * y
    return 1 if s > 0 else -1 if s < 0 else 0

def ans():
    N = int(input())
    AB =  []
    for i in range(N):
        a, b = map(int, input().split())
        AB.append([a, a + b, i])
    
    AB.sort(key=cmp_to_key(ans_key), reverse=True)
    print(*[i+1 for _, _, i in AB])


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
    # main()
    ans()

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