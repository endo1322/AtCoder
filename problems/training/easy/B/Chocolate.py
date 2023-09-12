'''https://atcoder.jp/contests/abc092/tasks/abc092_b'''

def main():
    N = int(input())
    D, X = map(int, input().split())
    A = [0] * N
    for i in range(N):
        A[i] = int(input())
    
    ans = X
    for a in A:
        ans += D // a
        if D % a != 0:
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()