'''https://atcoder.jp/contests/agc027/tasks/agc027_a'''

def main():
    N, x = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort()
    ans = 0

    for i in range(N):
        if x - a[i] < 0:
            ans = i
            break
        elif i == N - 1 and x != a[i]:
            ans = i
        elif i == N - 1 and x == a[i]:
            ans = i + 1
        x = x - a[i]
    print(ans)

if __name__ == '__main__':
    main()