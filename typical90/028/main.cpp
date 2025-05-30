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
    V<V<int>> Grid_sum(1001, V<int>(1001, 0));
    rep(i, N)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        Grid_sum[ly][lx]++;
        Grid_sum[ly][rx]--;
        Grid_sum[ry][lx]--;
        Grid_sum[ry][rx]++;
    }

    // solve
    V<int> ans(N);
    rep(i, 1001) rep3(j, 1, 1001) Grid_sum[i][j] += Grid_sum[i][j - 1];
    rep3(i, 1, 1001) rep(j, 1001) Grid_sum[i][j] += Grid_sum[i - 1][j];

    rep(i, 1001) rep(j, 1001) if (Grid_sum[i][j]) ans[Grid_sum[i][j] - 1]++;

    // output
    rep(i, N)
    {
        cout << ans[i] << endl;
    }
}