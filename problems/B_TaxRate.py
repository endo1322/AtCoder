'''https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b'''

def main():
    N = int(input())

    X = int(N / 1.08)
    # print(int(X))
    ans = ':('
    for i in [-1, 0, 1]:
        # print((X+i) * 1.08)
        if int((X + i) * 1.08) == N:
            ans = X + i
            print(ans)
            return
    print(ans)
    # if X.is_integer():
    #     print(X)
    # else:
    #     print(':(')

if __name__ == '__main__':
    main()