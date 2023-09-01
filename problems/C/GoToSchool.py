'''https://atcoder.jp/contests/abc142/tasks/abc142_c'''

def main():
    N = int(input())
    A = list(map(int, input().split()))

    A_sorted = sorted(enumerate(A), key=lambda x: x[1])
    ans = ' '.join(map(str, [x+1 for x, _ in A_sorted]))
    print(ans)

if __name__ == '__main__':
    main()