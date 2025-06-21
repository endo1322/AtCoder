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
    int N, H, M;
    cin >> N >> H >> M;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        A[i] = a;
        B[i] = b;
    }

    // solve
    int ans = 0;
    vector<vector<int>> dp(N + 1, vector<int>(H + 1, -1));
    dp[0][H] = M;
    rep(i, N)
    {
        rep(j, H + 1)
        {
            if (dp[i][j] == -1)
                continue;

            int h = j;
            int m = dp[i][j];
            int dh = A[i];
            int dm = B[i];
            int nh = h - dh;
            int nm = m - dm;

            if (nh >= 0)
                dp[i + 1][nh] = max(dp[i + 1][nh], m);

            if (nm >= 0)
                dp[i + 1][h] = max(dp[i + 1][h], nm);
        }
    }

    rep(i, N + 1)
    {
        rep(j, H + 1)
        {
            if (dp[i][j] != -1)
            {
                ans = i;
                break;
            }
        }
    }

    // output
    cout << ans << endl;
}