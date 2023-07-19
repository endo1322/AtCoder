'''https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_b'''

def main():
    N, A, B = map(int, input().split())
    S = list(input())
    AB = A + B
    # print(N, A, B, S)
    cnt = 0
    cnt_b = 1
    for i in range(N):
        if S[i] == 'a':
            if cnt < AB:
                print('Yes')
                cnt += 1
            else:
                print('No')
        elif S[i] == 'b':
            if cnt < AB and cnt_b <= B:
                print('Yes')
                cnt += 1
                cnt_b += 1
            else:
                print('No')
        else:
            print('No')

if __name__ == '__main__':
    main()