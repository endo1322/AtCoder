def main():
    N = int(input())
    A = [list(map(int, input())) for _ in range(N)]
    # print(N, A)

    for i in range(len(A)):
        for j in range(len(A[0])):
            if i == 0 and j == 0:
                t = A[0][0]
                A[0][0] = A[1][0]
                left = t
            elif i == 0:
                t = A[0][j]
                A[0][j] = left
                if j != N-1:
                    left = t
                else:
                    up = t
            elif i == N-1:
                t = A[i][j]
                if j != N-1:
                    A[i][j] = A[i][j+1]
                else:
                    A[i][j] = up
            elif j == 0:
                t = A[i][0]
                A[i][0] = A[i+1][0]
            elif j == N-1:
                t = A[i][j]
                A[i][j] = up
                up = t

    for a in A:
        print("".join(map(str, a)))

if __name__ == '__main__':
    main()

'''
in
4
0101
1101
1111
0000

out
1010
1101
0111
0001

in
2
11
11

5
01010
01001
10110
00110
01010

00101
11000
00111
00110
10100


'''