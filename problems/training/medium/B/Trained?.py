'''https://atcoder.jp/contests/abc065/tasks/abc065_b'''

def main():
    N = int(input())
    A = [0 for _ in range(N)]
    for i in range(N):
        A[i] = int(input())

    s = set()
    button = 0
    count = 0
    while True:
        count += 1
        if A[button] in s:
            ans = -1
            break
        elif A[button] == 2:
            ans = count
            break
        s.add(A[button])
        button = A[button] -1
    print(ans)

if __name__ == '__main__':
    main()