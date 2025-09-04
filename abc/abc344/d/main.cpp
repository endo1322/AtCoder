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
    string S;
    cin >> S;
    int N;
    cin >> N;
    V<pair<int, V<string>>> AS(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        V<string> T(a);
        rep(j, a)
        {
            string t;
            cin >> t;
            T[j] = t;
        }
        AS[i] = {a, T};
    }

    // solve
    V<V<int>> dp(N + 1, V<int>(S.size() + 1, INF));
    dp[0][0] = 0;
    rep3(i, 1, N + 1)
    {
        auto [T_size, T] = AS[i - 1];
        rep(j, S.size() + 1)
        {
            if (dp[i - 1][j] == INF)
                continue;
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            int cur_size = j;
            for (auto t : T)
            {
                int t_size = t.size();
                if (S.size() < cur_size + t_size)
                    continue;
                if (t == S.substr(cur_size, t_size))
                {
                    dp[i][j + t_size] = min(dp[i][j + t_size], dp[i - 1][j] + 1);
                }
            }
        }
    }

    int ans = dp[N][S.size()] != INF ? dp[N][S.size()] : -1;

    // output
    cout << ans << endl;
}