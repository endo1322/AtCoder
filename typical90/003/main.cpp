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

void dfs(V<V<int>> &Graph, V<int> &D, int v)
{
    for (auto nv : Graph[v])
    {
        if (D[nv] != -1)
            continue;

        D[nv] = D[v] + 1;
        dfs(Graph, D, nv);
    }
}

signed main()
{
    // input
    int N;
    cin >> N;
    V<V<int>> Graph(N);
    rep(i, N - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    // solve
    V<int> D_from0(N, -1);
    D_from0[0] = 0;
    dfs(Graph, D_from0, 0);

    int idx_st = 0;
    int mx_tmp = 0;
    rep(i, N)
    {
        if (D_from0[i] > mx_tmp)
        {
            mx_tmp = D_from0[i];
            idx_st = i;
        }
    }

    int ans = 0;
    V<int> D(N, -1);
    D[idx_st] = 0;
    dfs(Graph, D, idx_st);
    for (auto d : D)
        ans = max(ans, d);

    // output
    cout << ans + 1 << endl;
}