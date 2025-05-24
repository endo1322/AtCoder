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

int H, W;

void dfs(int x, int y, V<V<int>> &G, V<V<bool>> &used, int &ans)
{
    if (x >= W)
    {
        dfs(0, y + 1, G, used, ans);
        return;
    }

    if (y >= H)
    {
        int tmp = 0;
        rep(i, H) rep(j, W)
        {
            if (!used[i][j])
            {
                tmp ^= G[i][j];
            }
        }
        ans = max(ans, tmp);
        return;
    }

    if (used[y][x])
    {
        dfs(x + 1, y, G, used, ans);
        return;
    }

    dfs(x + 1, y, G, used, ans);

    if (x + 1 < W && !used[y][x + 1])
    {
        used[y][x] = true;
        used[y][x + 1] = true;
        dfs(x + 2, y, G, used, ans);
        used[y][x] = false;
        used[y][x + 1] = false;
    }

    if (y + 1 < H && !used[y + 1][x])
    {
        used[y][x] = true;
        used[y + 1][x] = true;
        dfs(x + 1, y, G, used, ans);
        used[y][x] = false;
        used[y + 1][x] = false;
    }
}

signed main()
{
    // input
    cin >> H >> W;
    V<V<int>> G(H, V<int>(W));
    rep(i, H)
    {
        rep(j, W)
        {
            cin >> G[i][j];
        }
    }

    // // solve
    int ans = 0;
    V<V<bool>> used(H, V<bool>(W, false));
    dfs(0, 0, G, used, ans);

    // output
    cout << ans << endl;
}