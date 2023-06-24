from collections import deque

def func(N, S):
    flag_pop = 0
    chars = deque()
    for i in range(N):
        if S[i] == '(':
            chars.append(S[i])
            flag_pop += 1
        elif S[i] == ')':
            if flag_pop > 0:
                while chars:
                    char = chars.pop()
                    if char == '(':
                        flag_pop -= 1
                        break
            else:
                chars.append(S[i])
        else:
            chars.append(S[i])
    result = ''.join(map(str, chars))
    return result


def main():
    N = int(input())
    S = list(input())
    # print(N, S)

    
    ans = func(N, S)

    print(ans) 

if __name__ == '__main__':

    main()

'''
8
a(b(d))c

5
a(b)(

2
()

6
)))(((

'''