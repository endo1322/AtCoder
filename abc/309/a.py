def main():
    A, B = map(int, input().split())
    if (1 <= A <= 9) and (1 <= B <= 9) and (A < B):
        A = A - 1
        B = B - 1
        aj = A % 3
        ai = (A - aj) // 3
        bj = B % 3
        bi = (B - bj) // 3
        # print(ai, aj, bi, bj)

        if ai == bi or aj == bj:
            print('Yes')
        else:
            print('No')
    else:
        print('No')

if __name__ == '__main__':
    main()

'''
in

'''