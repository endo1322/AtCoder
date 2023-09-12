'''https://atcoder.jp/contests/abc161/tasks/abc161_c'''

def main():
    N, K = map(int, input().split())
    x = N

    k = N // K
    x = N - K*k
    if abs(x - K) < x:
        ans = abs(x - K)
    else:
        ans = x
    
    print(ans)

if __name__ == '__main__':
    main()