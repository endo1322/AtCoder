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
    int N, M, X;
    cin >> N >> M >> X;
    V<V<int>> Graph(N);
    V<V<int>> R_Graph(N);
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Graph[a].push_back(b);
        R_Graph[b].push_back(a);
    }

    // solve
    V<V<int>> distance(N, V<int>(2, INF));
    PQG<tuple<int, int, bool>> pq;
    distance[false][0] = 0;
    pq.push({0, 0, false});
    while (!pq.empty())
    {
        auto [d, from, is_reverse] = pq.top();
        pq.pop();

        if (d > distance[from][is_reverse])
            continue;

        for (auto to : Graph[from])
        {
            int cost = is_reverse ? X : 0;
            int nd = d + 1 + cost;
            if (nd < distance[to][false])
            {
                distance[to][false] = nd;
                pq.push({nd, to, false});
            }
        }
        for (auto to : R_Graph[from])
        {
            int cost = is_reverse ? 0 : X;
            int nd = d + 1 + cost;
            if (nd < distance[to][true])
            {
                distance[to][true] = nd;
                pq.push({nd, to, true});
            }
        }
    }
    int ans = min(distance[N - 1][false], distance[N - 1][true]);

    // output
    cout << ans << endl;
}