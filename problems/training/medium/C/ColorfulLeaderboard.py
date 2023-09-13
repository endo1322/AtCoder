'''https://atcoder.jp/contests/abc064/tasks/abc064_c'''

def main():
    N = int(input())
    A = list(map(int, input().split()))

    s = set()
    count = 0
    for a in A:
        if a // 400 < 8:
            s.add(a // 400)
        elif a // 400 >= 8:
            count += 1
    if len(s) == 0 and count > 0:
        mini = 1
    else:
        mini = len(s)
        
    max = len(s) + count
    print(mini, max)

if __name__ == '__main__':
    main()