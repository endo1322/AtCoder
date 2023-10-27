from collections import deque
import pprint

H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]
next = {'s':'n', 'n':'u', 'u':'k', 'k':'e', 'e':'s'}
seen = [[False] * W for _ in range(H)]

def ans_snuke(x, y):
    seen[y][x] = True
    if y == H-1 and x == W-1:
        return
    ns = next[S[y][x]]
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if 0 <= nx <= W-1 and 0 <= ny <= H-1:
            if S[ny][nx] not in next:
                continue
            if seen[ny][nx] == True:
                continue
            if S[ny][nx] == ns:
                ans_snuke(nx, ny)

def ans():
    # H, W = map(int, input().split())
    # S = [list(input()) for _ in range(H)]
    if S[0][0] not in next:
        print('No')
    else:
        ans_snuke(0, 0)
        if seen[H-1][W-1] == True:
            print('Yes')
        else:
            print('No')

def snuke(H, W, S):
    open = deque([[0, 0]])
    o_s = S.copy()
    # print(o_s)
    open_s = deque([o_s])

    while open:
        x, y = open.pop()
        S = open_s.pop()
        S_copy = S.copy()
        moji = S_copy[y][x]
        S_copy[y][x]=0
        # print(moji)
        if moji == 's':
            next = 'n'
        elif moji == 'n':
            next = 'u'
        elif moji == 'u':
            next = 'k'
        elif moji == 'k':
            next = 'e'
        elif moji == 'e':
            next = 's'
        else:
            return 'No'

        for s in [-1, 0, 1]:
            if not (0 <= y + s <= H-1):
                continue
            for t in [-1, 0, 1]:
                if not (0 <= x + t <= W-1):
                    continue
                if S_copy[y+s][x+t] == next:
                    open.append([x+t, y+s])
                    open_s.append(S_copy)
                    # print(S_copy)
                    if y+s == H-1 and x+t == W-1:
                        return 'Yes'
    return 'No'

def main():
    H, W = map(int, input().split())
    S = [list(input()) for _ in range(H)]

    ans = snuke(H, W, S)

    print(ans)

if __name__ == '__main__':
    # main()
    ans()

'''
in
2 3
sns
euk

out
Yes

in
2 2
ab
cd

out
No

in
5 7
skunsek
nukesnu
ukeseku
nsnnesn
uekukku

out
Yes

'''