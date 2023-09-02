def main():
    N, D, P = map(int, input().split())
    F = list(map(int, input().split()))

    F.sort(reverse=True)
    sum = 0
    for i in range(N//D+1):
        tmp = 0
        for j in range(D):
            if i*D+j >= N:
                break
            tmp += F[i*D+j]
        if P > tmp:
            sum += tmp
        else:
            sum += P
    print(sum)

if __name__ == '__main__':
    main()