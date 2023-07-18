def ans():
    N = int(input())
    S = [input() for _ in range(N)]
    se = set()
    for s in S:
        se.add(min(s, s[::-1]))
    print(len(se))

def main():
    N = int(input())
    S = [input() for _ in range(N)]
    # print(N, S)
    flag = False
    for i in range(N):
        if i >= len(S):
            continue
        s_a = S[i]
        for j in range(i+1, N):
            if flag == True:
                j = j - 1
                flag = False
            if j >= len(S):
                continue
            s_b = S[j]
            if s_a == s_b:
                del S[j]
                N = N - 1
                flag = True
                # j = j - 1
            if s_a == s_b[::-1]:
                del S[j]
                N = N - 1
                flag = True
                # j = j - 1
    print(len(S))

if __name__ == '__main__':
    # main()
    ans()

'''
in
6
a
abc
de
cba
de
abc

'''