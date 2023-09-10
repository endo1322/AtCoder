def main():
    N = int(input())
    J = []

    for i in range(1, 10):
        if N % i == 0:
            J.append(i)
    # print(J)

    ans = []
    for i in range(N+1):
        flag = True
        for j in J:
            if i % (N / j) == 0:
                a = str(j)
                flag = False
                break
        if flag:
            a = '-'
        ans.append(a)
    print("".join(ans))

if __name__ == '__main__':
    main()