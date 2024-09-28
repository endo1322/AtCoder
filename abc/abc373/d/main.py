import sys
sys.setrecursionlimit(10**9)

def dfs(G, memo, weight, v, w, now_w, mx, mn, tmp):
    weight[v] = w + now_w
    memo[v] = True

    mx = max(mx, weight[v])
    mn = min(mn, weight[v])

    tmp.append(v)

    for vv, ww in G[v]:
        if memo[vv]:
            continue
        dfs(G, memo, weight, vv, ww, weight[v], mx, mn, tmp)

def main():
    N, M = map(int, input().split())
    G = [[] for _ in range(N)]
    for i in range(M):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        G[u].append((v, w))
        G[v].append((u, -w))

    memo = [False] * N
    weight = [0] * N

    mx = -10**19
    mn = 10**19

    for i in range(N):
        if memo[i]:
            continue
        tmp = [i]
        memo[i] = True

        for v, w in G[i]:
            if memo[v]:
                continue
            dfs(G, memo, weight, v, w, 0, mx, mn, tmp)
            ofset = 0
            if mx > 10**18:
                ofset = 10**18 - mx
            elif mn < -10**18:
                ofset = -10**18 - mn

        for t in tmp:
            weight[t] += ofset

    for i in range(N):
        print(weight[i])

if __name__ == '__main__':
    main()