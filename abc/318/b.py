def main():
    N = int(input())
    A = [0] * N
    B = [0] * N
    C = [0] * N
    D = [0] * N
    for i in range(N):
        A[i], B[i], C[i], D[i]= map(int, input().split())
    # s1 = set([i for i in range(A[0], B[0]+1)])
    # s2 = set([i for i in range(C[0], D[0]+1)])
    # for i in range(1, N):
    #     ss1 =set([num for num in range(A[i], B[i]+1)])
    #     ss2 = set([num for num in range(C[i], D[i]+1)])

    #     s1 = s1 & ss1
    #     s2 = s2 & ss2

    # print(s1, s2)

    s1 = set([(ni, nj) for ni in range(A[0], B[0]) for nj in range(C[0], D[0])])

    for i in range(1, N):
        s2 = set([(ni, nj) for ni in range(A[i], B[i]) for nj in range(C[i], D[i])])
        s1 = s1 | s2

    print(len(s1))

if __name__ == '__main__':
    main()