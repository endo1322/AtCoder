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

void dfs(int v, int ct, V<V<int>> &G, set<int> &tmp, V<bool> &visited)
{
    visited[v] = true;

    if (ct % 2 == 0)
    {
        tmp.insert(v);
    }

    for (auto nv : G[v])
    {
        if (!visited[nv])
            dfs(nv, ct + 1, G, tmp, visited);
    }
}

signed main()
{
    // input
    int N;
    cin >> N;
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

    // solve
    set<int> tmp;
    V<bool> visited(N, false);
    dfs(0, 0, G, tmp, visited);

    V<int> ans;
    if (tmp.size() >= N / 2)
    {
        for (auto x : tmp)
            ans.push_back(x);
    }
    else
    {
        rep(i, N) if (tmp.count(i) == 0)
            ans.push_back(i);
    }

    // output
    rep(i, N / 2)
    {
        cout << ans[i] + 1;
        if (i != N / 2 - 1)
            cout << " ";
        else
            cout << endl;
    }
}