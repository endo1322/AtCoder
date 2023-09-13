'''https://atcoder.jp/contests/abc060/tasks/abc060_b'''

def main():
    A, B, C = map(int, input().split())

    s = set()
    count = 1
    aa = A
    if aa == 1:
        print('YES')
    else:
        while True:
            a = aa % B
            if a == C:
                ans = 'YES'
                break
            if a in s:
                ans = 'NO'
                break
            s.add(a)
            count += 1
            aa = A * count
        print(ans)

if __name__ == '__main__':
    main()