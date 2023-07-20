'''https://atcoder.jp/contests/abc121/tasks/abc121_b'''

def main():
    N, M, C = map(int, input().split())
    B = list(map(int, input().split()))
    A = [list(map(int, input().split())) for _ in range(N)]
    # print(N, M, C, B, A)
    cnt = 0
    for i in range(N):
        sum = 0
        for j in range(M):
            sum += A[i][j] * B[j]
        sum += C
        if sum > 0:
            cnt += 1
    print(cnt)


if __name__ == '__main__':
    main()