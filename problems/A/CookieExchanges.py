'''https://atcoder.jp/contests/agc014/tasks/agc014_a'''

def main():
    A, B, C = map(int, input().split())
    if A % 2 == 1 or B % 2 == 1 or C % 2 == 1:
        print(0)
        return
    elif A == B and B == C and A == C:
        print(-1)
        return
    cnt = 0
    while True:
        cnt += 1
        aa = int(A / 2)
        bb = int(B / 2)
        cc = int(C / 2)
        A = bb + cc
        B = aa + cc
        C = aa + bb
        if A % 2 == 1 or B % 2 == 1 or C % 2 == 1:
            print(cnt)
            return
        elif A == B and B == C and A == C:
            print(-1)
            return

if __name__ == '__main__':
    main()