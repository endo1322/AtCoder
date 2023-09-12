'''https://atcoder.jp/contests/abc116/tasks/abc116_b'''

def main():
    s = int(input())
    anss = set({float(s)})
    n = s
    count = 2
    while True:
        if n % 2 == 0:
            f = n / 2
        else:
            f = 3 * n + 1
        if f in anss:
            ans = count
            break
        else:
            anss.add(f)
        n = f   
        count += 1
    print(ans)

if __name__ == '__main__':
    main()