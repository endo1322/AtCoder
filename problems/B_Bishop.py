'''https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b'''

def main():
    H, W = map(int, input().split())
    ans = H * W / 2
    if H == 1 or W == 1:
        print(1)
    elif H % 2 == 0 or W % 2 == 0:
        print(int(ans))
    else:
        print(int(ans) + 1)

if __name__ == '__main__':
    main()