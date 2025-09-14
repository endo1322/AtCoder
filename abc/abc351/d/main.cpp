#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define rep3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define rrep(i, n) for (int i = (int)(n) - 1; (i) >= 0; --(i))
#define rrep3(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); --(i))
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
#define int long long
#define ll long long
#define double long double
using mint = modint998244353;
template <class T>
using V = vector<T>;
template <class T>
using P = pair<T, T>;
template <class T>
using PQ = priority_queue<T>;
template <class T>
using PQG = priority_queue<T, V<T>, greater<T>>;
const long long INF = LLONG_MAX;
const long long MIN_INF = LLONG_MIN;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<pair<int, int>> neighbors_generic(
    int y, int x, int H, int W,
    const vector<pair<int, int>> &dirs)
{
    vector<pair<int, int>> res;
    res.reserve(dirs.size());
    for (auto [dy, dx] : dirs)
    {
        int ny = y + dy, nx = x + dx;
        if (0 <= ny && ny < H && 0 <= nx && nx < W)
        {
            res.emplace_back(ny, nx);
        }
    }
    return res;
}
vector<pair<int, int>> neighbors4(int y, int x, int H, int W) { return neighbors_generic(y, x, H, W, D4); }
vector<pair<int, int>> neighbors8(int y, int x, int H, int W) { return neighbors_generic(y, x, H, W, D8); }

signed main()
{
    // input
    int H, W;
    cin >> H >> W;
    V<V<char>> S(H, V<char>(W));
    rep(i, H) rep(j, W)
    {
        char c;
        cin >> c;
        S[i][j] = c;
    }

    // solve
    int ans = 0;
    V<V<int>> map(H, V<int>(W, -1));
    rep(i, H) rep(j, W)
    {
        if (S[i][j] == '#')
        {
            map[i][j] = 0;
            for (auto [ny, nx] : neighbors4(i, j, H, W))
            {
                if (S[ny][nx] == '.')
                    map[ny][nx] = 1;
            }
        }
    }

    queue<P<int>> que;
    V<V<bool>> seen(H, V<bool>(W, false));
    rep(i, H) rep(j, W)
    {
        if (map[i][j] == -1)
            que.push({i, j});
    }

    auto dfs = [&](auto dfs, int y, int x, set<P<int>> &tmp) -> void
    {
        if (seen[y][x])
            return;
        seen[y][x] = true;
        tmp.insert({y, x});
        for (auto [ny, nx] : neighbors4(y, x, H, W))
        {
            if (map[ny][nx] == -1)
            {
                dfs(dfs, ny, nx, tmp);
            }
            else if (map[ny][nx] == 1)
            {
                tmp.insert({ny, nx});
            }
        }
    };
    while (!que.empty())
    {
        auto [y, x] = que.front();
        que.pop();
        if (seen[y][x])
            continue;
        seen[y][x] = true;
        set<P<int>> tmp;
        tmp.insert({y, x});
        for (auto [ny, nx] : neighbors4(y, x, H, W))
        {
            if (map[ny][nx] == -1)
            {
                dfs(dfs, ny, nx, tmp);
            }
            else if (map[ny][nx] == 1)
            {
                tmp.insert({ny, nx});
            }
        }
        for (auto [ty, tx] : tmp)
        {
            if (map[ty][tx] != -1)
                continue;
            map[ty][tx] = tmp.size();
        }
    }
    rep(i, H) rep(j, W) ans = max(ans, map[i][j]);

    // output
    cout << ans << endl;
}