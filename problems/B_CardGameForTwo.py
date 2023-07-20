'''https://atcoder.jp/contests/abc088/tasks/abc088_b'''

def main():
    N = int(input())
    A = list(map(int, input().split()))
    A.sort(reverse=True)
    sum_a = 0
    sum_b = 0
    for i in range(N):
        if i % 2 == 0:
            sum_a += A[i]
        else:
            sum_b += A[i]
    print(sum_a-sum_b)

if __name__ == '__main__':
    main()