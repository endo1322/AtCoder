'''https://atcoder.jp/contests/abc074/tasks/abc074_b'''

def main():
    N = int(input())
    K = int(input())
    x = list(map(int, input().split()))
    # print(N,K,x)
    sum = 0
    for i in range(N):
        sum += min(x[i], K-x[i])*2
    print(sum)
    
if __name__ == '__main__':
    main()