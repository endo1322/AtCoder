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

bool dfs(vector<vector<int>> &G, int v, int parent, vector<bool> &seen, vector<bool> &finished)
{
    seen[v] = true;
    for (auto v2 : G[v])
    {
        if (v2 == parent)
            continue;

        if (finished[v2])
            continue;

        if (seen[v2] && !finished[v2])
            return true;

        if (dfs(G, v2, v, seen, finished))
            return true;
    }
    finished[v] = true;
    return false;
}

signed main()
{
    // input
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // solve
    string ans;
    vector<bool> seen(N, false);
    vector<bool> finished(N, false);
    if (dfs(G, 0, -1, seen, finished))
    {
        ans = "Yes";
    }
    else
    {
        ans = "No";
    }

    rep(i, N)
    {
        if (!seen[i])
        {
            ans = "No";
            break;
        }
    }

    // output
    cout << ans << endl;
}