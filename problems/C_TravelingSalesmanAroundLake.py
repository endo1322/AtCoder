'''https://atcoder.jp/contests/abc160/tasks/abc160_c'''

def main():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))

    diff = []
    max = 0
    for i in range(N):
        if i == N-1:
            d = (K-A[i])+A[0]
            diff.append(d)
        else:
            d = A[i+1]-A[i]
            diff.append(d)
        if d > max:
            max = d
            max_i = i
    sum = 0
    # print(diff, max, max_i)
    for i in range(N):
        if i != max_i:
            sum += diff[i]
    print(sum)
    
    # min_d = float('inf')
    # for i in range(N):
    #     sum = 0
    #     for j in range(N-1):
    #         if i+j+1 <= N-1:
    #             sum += A[i+j+1] - A[i+j]
    #         elif i+j == N-1:
    #             sum += (K-A[i+j]) + A[0]
    #         else:
    #             sum += A[(i+j)-N+1] - A[(i+j)-N]
    #     if sum < min_d:
    #         min_d = sum
    # print(min_d)

if __name__ == '__main__':
    main()