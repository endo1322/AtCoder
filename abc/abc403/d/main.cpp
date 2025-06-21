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
    int N, D;
    cin >> N >> D;
    set<int> st;
    map<int, int> cnt;
    rep(i, N)
    {
        int a;
        cin >> a;
        st.insert(a);
        cnt[a]++;
    }

    // solve
    int ans = 0;
    if (D == 0)
    {
        int ans = 0;
        for (auto [a, c] : cnt)
        {
            ans += c - 1;
        }
        cout << ans << endl;
        return 0;
    }
    V<V<int>> tmp(D);
    V<int> tmp_last(D, -1);
    for (auto a : st)
    {
        int d = a % D;
        int q = a / D;
        if (tmp_last[d] != q - 1)
            tmp[d].push_back(0);
        tmp_last[d] = q;
        tmp[d].push_back(cnt[a]);
    }
    rep(i, D)
    {
        V<V<int>> dp(2, V<int>(tmp[i].size() + 1, 0));
        int sum = 0;
        rep(j, tmp[i].size()) sum += tmp[i][j];
        rep(j, tmp[i].size())
        {
            dp[0][j + 1] = dp[1][j] + tmp[i][j];
            dp[1][j + 1] = max(dp[0][j], dp[1][j]);
        }
        ans += sum - max(dp[0][tmp[i].size()], dp[1][tmp[i].size()]);
    }

    // output
    cout << ans << endl;
}