def main():
    N, P, Q = map(int, input().split())
    D = list(map(int, input().split()))
    # print(N, P, Q, D)

    max = float('inf')
    for i in range(N):
        if D[i] < max:
            max = D[i]
    sum = Q + max
    if sum > P:
        print(P)
    else:
        print(sum)

if __name__ == '__main__':
    main()

'''
in

'''