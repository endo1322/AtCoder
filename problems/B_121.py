'''https://atcoder.jp/contests/abc086/tasks/abc086_b'''

def main():
    a, b = input().split()
    ab = int (a+b)
    # print(ab)
    for i in range(1, 320):
        if ab == i*i:
            print('Yes')
            return
    print('No')

if __name__ == '__main__':
    main()