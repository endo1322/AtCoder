'''https://atcoder.jp/contests/abc156/tasks/abc156_c'''

def main():
    N = int(input())
    X = list(map(int, input().split()))
    # print(N, X)
    sum = 0
    ans = 0
    for i in range(N):
        sum += 2 * X[i]
    # print(sum)
    o = round(sum/(N*2))
    # print(o)
    for i in range(N):
        ans += (X[i] - o)**2
    print(ans)


if __name__ == '__main__':
    main()