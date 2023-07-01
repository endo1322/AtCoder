def main():
    N, M = map(int, input().split())
    C = list(input().split())
    D = list(input().split())
    P = list(map(int, input().split()))
    # print(N, M, C, D, P)

    table = {}
    for i, d in enumerate(D):
        table[d] = P[i+1]
    table['else'] = P[0]

    # print(table)

    sum = 0
    for i, c in enumerate(C):
        # print(c in table)
        if c in table:
            sum += table[c]
        else:
            sum += table['else']
    print(sum)

if __name__ == '__main__':
    main()

'''
in
3 2
red green blue
blue red
800 1600 2800
out
5200

in
3 2
code queen atcoder
king queen
10 1 1
out
21

'''