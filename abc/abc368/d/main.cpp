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
    int N, K;
    cin >> N >> K;
    V<V<int>> G(N);
    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    set<int> V;
    rep(i, K)
    {
        int v;
        cin >> v;
        v--;
        V.insert(v);
    }

    // solve
    if (V.size() == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    set<int> visited;
    dsu D(N);
    auto dfs = [&](auto dfs, int v, int p) -> void
    {
        visited.insert(v);

        for (auto u : G[v])
        {
            if (!visited.count(u))
                dfs(dfs, u, v);
        }

        if (V.count(v) || D.size(v) > 1)
        {
            D.merge(v, p);
        }
    };

    int st = *V.begin();
    visited.insert(st);
    for (auto v : G[st])
    {
        dfs(dfs, v, st);
    }
    int ans = D.size(*V.begin());

    // output
    cout << ans << endl;
}