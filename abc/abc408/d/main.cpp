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
    int T;
    cin >> T;
    vector<int> Ans(T);
    rep(i, T)
    {
        int N;
        cin >> N;
        string S;
        cin >> S;

        V<V<int>> dp(3, V<int>(N + 1, 0));
        // 0
        rep(i, N)
        {
            if (S[i] != '0')
            {
                dp[0][i + 1] = dp[0][i] + 1;
            }
            else
            {
                dp[0][i + 1] = dp[0][i];
            }
        }

        // 1
        rep(i, N)
        {
            if (S[i] != '1')
            {
                dp[1][i + 1] = min(dp[1][i] + 1, dp[0][i] + 1);
            }
            else
            {
                dp[1][i + 1] = min(dp[1][i], dp[0][i]);
            }
        }

        // 2
        rep(i, N)
        {
            if (S[i] != '0')
            {
                dp[2][i + 1] = min(dp[2][i] + 1, dp[1][i] + 1);
            }
            else
            {
                dp[2][i + 1] = min(dp[2][i], dp[1][i]);
            }
        }

        Ans[i] = min(dp[0][N], min(dp[1][N], dp[2][N]));
    }

    // output
    rep(i, T)
    {
        cout << Ans[i] << endl;
    }
}