'''https://atcoder.jp/contests/abc094/tasks/abc094_b'''
import bisect

def main():
    N, M, X = map(int, input().split())
    A = list(map(int, input().split()))

    idx = bisect.bisect(A, X)

    if idx < M - idx:
        print(idx)
    else:
        print(M - idx)

if __name__ == '__main__':
    main()