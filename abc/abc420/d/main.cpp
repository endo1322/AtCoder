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

signed main()
{
    // input
    int H, W;
    cin >> H >> W;
    V<V<char>> A(H, V<char>(W));
    P<int> st, gl;
    rep(i, H)
    {
        rep(j, W)
        {
            char c;
            cin >> c;
            if (c == 'S')
                st = {j, i};
            if (c == 'G')
                gl = {j, i};
            A[i][j] = c;
        }
    }

    // solve
    int ans = INF;
    queue<pair<P<int>, int>> q;
    q.push({st, 0});
    V<V<V<int>>> dist(H, V<V<int>>(W, V<int>(2, INF)));
    int st_x = st.first;
    int st_y = st.second;
    dist[st_y][st_x][0] = 0;

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        auto xy = p.first;
        int x = xy.first;
        int y = xy.second;
        int parity = p.second;
        int cost = dist[y][x][parity];

        for (auto d : D4)
        {
            int nx = x + d.first;
            int ny = y + d.second;
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                continue;
            char nc = A[ny][nx];
            if (nc == '#')
                continue;
            if (nc == '.' || (parity == 0 && nc == 'o') || (parity == 1 && nc == 'x') || nc == 'S' || nc == 'G')
            {
                if (dist[ny][nx][parity] <= cost + 1)
                    continue;
                dist[ny][nx][parity] = cost + 1;
                q.push({{nx, ny}, parity});
            }
            else if (nc == '?')
            {
                if (dist[ny][nx][parity ^ 1] <= cost + 1)
                    continue;
                dist[ny][nx][parity ^ 1] = cost + 1;
                q.push({{nx, ny}, parity ^ 1});
            }
        }
    }

    ans = min(dist[gl.second][gl.first][0], dist[gl.second][gl.first][1]);
    if (ans == INF)
        ans = -1;

    // output
    cout << ans << endl;
}