def main():
    N = int(input())
    A = list(map(int, input().split()))
    # print(N, A)
    
    sums = []
    for i in range(N):
        sum = 0
        for j in range(7):
            sum += A[i*7+j]
        sums.append(sum)

    for i in range(len(sums)):
        print(sums[i])

if __name__ == '__main__':
    main()

'''
in
2
1000 2000 3000 4000 5000 6000 7000 2000 3000 4000 5000 6000 7000 8000

'''