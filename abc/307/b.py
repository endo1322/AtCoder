def check(N, S):
    for i in range(N):
        for j in range(N):
            if i != j:
                flag = True
                charlist = S[i] + S[j]
                len_charlist = len(charlist)
                # print(charlist)
                # median = int(len(charlist) / 2)
                # if len(charlist) % 2 == 0:
                #     pre = charlist[:median]
                #     post = charlist[median:]
                #     post = post[::-1]
                #     # print(pre, post)
                # else:
                #     pre = charlist[:median]
                #     post = charlist[median+1:]
                #     post = post[::-1]
                # if pre == post:
                #     return 1
                for k in range(len_charlist):
                    if charlist[k] != charlist[-k-1]:
                        # print(charlist[k], charlist[-k-1])
                        flag = False
                if flag:
                    # print(charlist)
                    return 1

def main():
    N = int(input())
    S = [input() for _ in range(N)]
    # print(N, S)

    if check(N, S) == 1:
        print('Yes')
    else:
        print('No')
    # print(check(N, S))

if __name__ == '__main__':
    main()

'''
in
5
ab
ccef
da
a
fe

3
a
b
aba

2
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

'''