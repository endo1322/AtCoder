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

int sum_arithmetic(int n)
{
    return n * (n + 1) / 2;
}

signed main()
{
    // input
    int N, M;
    cin >> N >> M;
    V<P<int>> XM(M);
    rep(i, M)
    {
        int x;
        cin >> x;
        x--;
        XM[i].first = x;
    }
    rep(i, M) cin >> XM[i].second;

    // solve
    sort(all(XM));
    if (XM[0].first != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (XM[M - 1].first != N - 1)
    {
        XM.push_back({N - 1, 0});
    }

    int ans = 0;
    int stock = XM[0].second - 1;
    rep3(i, 1, (int)XM.size())
    {
        int x_prev = XM[i - 1].first;
        int a_prev = XM[i - 1].second;
        int x_curr = XM[i].first;
        int a_curr = XM[i].second;
        int need = a_curr > 0 ? x_curr - x_prev - 1 : x_curr - x_prev;
        if (need > stock)
        {
            ans = -1;
            break;
        }
        stock -= need;
        ans += sum_arithmetic(need) + stock * (x_curr - x_prev);
        stock += a_curr > 0 ? a_curr - 1 : a_curr;
    }
    if (stock > 0)
        ans = -1;

    // output
    cout << ans << endl;
}