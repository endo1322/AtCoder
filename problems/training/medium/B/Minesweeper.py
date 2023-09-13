'''https://atcoder.jp/contests/abc075/tasks/abc075_b'''

def main():
    H, W = map(int, input().split())
    S = [None for _ in range(H)]
    for i in range(H):
        S[i] = list(input())
    diff = [[-1, -1], [0, -1], [1, -1], [-1, 0], [1, 0], [-1, 1], [0, 1], [1, 1]]

    for h in range(H):
        for w in range(W):
            if S[h][w] == '.':
                count = 0
                for dx, dy in diff:
                    if (0 <= h+dy < H and 0 <= w+dx < W) and S[h+dy][w+dx] == '#':
                        count += 1
                S[h][w] = count
    print('\n'.join([''.join(map(str, s)) for s in S]))

if __name__ == '__main__':
    main()