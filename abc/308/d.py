from collections import deque
import pprint

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
    main()

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