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
    int T;
    cin >> T;
    V<V<int>> Ans(T);
    rep(i, T)
    {
        // input
        int N, M, X, Y;
        cin >> N >> M >> X >> Y;
        X--;
        Y--;
        V<PQG<int>> G(N);
        rep(j, M)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].push(v);
            G[v].push(u);
        }

        // solve
        V<int> min_path;
        V<bool> visited(N, false);
        auto dfs = [&](auto dfs, int u) -> bool
        {
            visited[u] = true;
            min_path.push_back(u);
            if (u == Y)
                return true;
            while (!G[u].empty())
            {
                int v = G[u].top();
                G[u].pop();
                if (!visited[v])
                {
                    if (dfs(dfs, v))
                        return true;
                }
            }
            min_path.pop_back();
            return false;
        };
        dfs(dfs, X);

        // output
        Ans[i] = min_path;
    }

    // output
    rep(i, T)
    {
        for (auto v : Ans[i])
        {
            cout << v + 1;
            if (v != Ans[i].back())
                cout << " ";
        }
        cout << endl;
    }
}