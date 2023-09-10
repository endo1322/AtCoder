def main():
    N, M = map(int, input().split())
    L = list(map(int, input().split()))

    LL = []
    for i, l in enumerate(L):
        ll = 0
        for j in range(i+1):
            ll += L[j]
        LL.append(ll)
    print(LL)

    for i, l in enumerate(LL):
        count = 1
        

    # for l in L:
    #     count = 1



if __name__ == '__main__':
    main()