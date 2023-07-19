'''https://atcoder.jp/contests/abc139/tasks/abc139_b'''

def main():
    A, B = map(int, input().split())
    # print(A,B)
    if B == 1:
        print(0)
    else:
        num = A
        count = 1
        while True:
            if num >= B:
                print(count)
                break
            else:
                count += 1
                num += A - 1

if __name__ == '__main__':
    main()