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
    int Mg;
    cin >> Mg;
    V<V<bool>> G(N, V<bool>(N, false));
    rep(i, Mg)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u][v] = true;
        G[v][u] = true;
    }
    int Mh;
    cin >> Mh;
    V<V<bool>> H(N, V<bool>(N, false));
    rep(i, Mh)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        H[u][v] = true;
        H[v][u] = true;
    }
    V<V<int>> A(N, V<int>(N, 0));
    rep(i, N - 1)
    {
        rep3(j, i + 1, N)
        {
            int a;
            cin >> a;
            A[i][j] = a;
            A[j][i] = a;
        }
    }

    // solve
    int ans = INF;
    V<int> P(N, 0);
    rep(i, N) P[i] = i;
    do
    {
        int cost = 0;
        V<V<bool>> H_copy = H;
        rep(u, N)
        {
            rep(v, N)
            {
                if (u == v)
                    continue;
                if (G[u][v] != H_copy[P[u]][P[v]])
                {
                    H_copy[P[u]][P[v]] = G[u][v];
                    H_copy[P[v]][P[u]] = G[u][v];
                    cost += A[P[u]][P[v]];
                }
            }
        }
        ans = min(ans, cost);
    } while (next_permutation(all(P)));

    // output
    cout << ans << endl;
}