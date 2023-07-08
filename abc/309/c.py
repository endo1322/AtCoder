import copy

def main():
    N, K = map(int, input().split())
    A = []
    B = []
    AB = []
    max = 0
    mini = float('inf')
    for i in range(N):
        a, b = map(int, input().split())
        # if a > max:
        #     max = a
        # if a < mini:
        #     mini = a
        AB.append([a, b])
        # A.append(a)
        # B.append(b)
    # print(N, A, B, max, mini)
    day = 0
    AB.sort()
    AB_copy = copy.deepcopy(AB)
    print(AB)
    # day = AB[0][0]
    for i in range(N):
        sum = 0
        # print(AB_copy)
        mini = AB_copy[i][0]
        for j in range(N):
            if AB[j][0] == 0:
                continue
            # print(AB[j][1])
            sum += AB[j][1]
            AB[j][0] -= mini
        AB[i][0] = 0
        print(sum, mini)
        if sum <= K:
            print(day)
            return
        day += mini

    # for i in range(max):
    #     sum = 0
    #     for j in range(N):
    #         if A[j] == 0:
    #             continue
    #         sum += B[j]
    #         A[j] -= 1
    #     if sum <= K:
    #         print(i+1)
    #         return

if __name__ == '__main__':
    main()

'''
in
4 8
6 3
2 5
1 9
4 2
'''