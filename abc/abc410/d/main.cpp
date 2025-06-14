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
    int N, M;
    cin >> N >> M;
    V<V<P<int>>> Graph(N);
    rep(i, M)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        Graph[a].push_back({b, w});
    }

    // solve
    int ans = INF;
    set<pair<int, int>> visited;
    auto f = [&](auto f, int p, int score, int weight) -> void
    {
        score ^= weight;
        visited.insert({p, score});

        if (p == N - 1)
        {
            ans = min(ans, score);
        }

        for (auto [b, w] : Graph[p])
        {
            if (!visited.count({b, score ^ w}))
            {
                f(f, b, score, w);
            }
        }

        score ^= weight;
    };
    for (auto [b, w] : Graph[0])
    {
        f(f, b, 0, w);
    }
    if (ans == INF)
    {
        ans = -1;
    }

    // output
    cout << ans << endl;
}