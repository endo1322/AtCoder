'''https://atcoder.jp/contests/abc149/tasks/abc149_c'''

import math

def main():
    X = int(input())
    # p = set([i for i in range(2, 100004)])
    dect = int(math.sqrt(X))

    while True:
        flag_p = True
        for d in range(2, dect):
            if X % d == 0:
                flag_p = False
                break
        if flag_p:
            ans = X
            break
        else:
            X += 1
    print(ans)
    
if __name__ == '__main__':
    main()