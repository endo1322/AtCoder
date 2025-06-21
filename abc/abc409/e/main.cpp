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
    int N;
    cin >> N;
    V<int> X(N);
    rep(i, N) cin >> X[i];
    V<V<P<int>>> G(N);
    rep(i, N - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    // solve
    int ans = 0;
    V<bool> visited(N, false);
    auto f = [&](auto f, int u) -> void
    {
        visited[u] = true;

        for (auto [v, w] : G[u])
        {
            if (visited[v])
                continue;
            f(f, v);
            X[u] += X[v];
            ans += abs(X[v]) * w;
            X[v] = 0;
        }
    };
    f(f, 0);

    // output
    cout << ans << endl;
}