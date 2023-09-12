'''https://atcoder.jp/contests/abc157/tasks/abc157_b'''

def main():
    A = [list(map(int, input().split())) for _ in range(3)]
    N = int(input())
    B = [int(input()) for _ in range(N)]
    # print(A, N, b)
    bingo = [[False for _ in range(3)] for _ in range(3)]
    # print(bingo)
    for i in range(N):
        b = B[i]
        for j in range(3):
            for k in range(3):
                if A[j][k] == b:
                    bingo[j][k] = True
    # print(bingo)
    for i in range(3):
        yoko = True
        tate = True
        for j in range(3):
            if not(bingo[i][j]):
                yoko = False
            if not(bingo[j][i]):
                tate = False
        if yoko == True or tate == True:
            print('Yes')
            return
    if (bingo[0][0] and bingo[1][1] and bingo[2][2]) or (bingo[0][2] and bingo[1][1] and bingo[2][0]):
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()