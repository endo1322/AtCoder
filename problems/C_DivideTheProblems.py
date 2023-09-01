'''https://atcoder.jp/contests/abc132/tasks/abc132_c'''

def main():
    N = int(input())
    d = list(map(int, input().split()))

    d.sort()

    k_under = int(N / 2 -1)
    k_up = int(N / 2)
    ans = d[k_up] - d[k_under]

    print(ans)

if __name__ == '__main__':
    main()