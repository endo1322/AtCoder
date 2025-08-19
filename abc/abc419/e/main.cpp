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
    int N, M, L;
    cin >> N >> M >> L;
    vector<int> A(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        A[i] = a % M;
    }

    // solve
    V<V<int>> dp(L + 1, V<int>(M, INF));
    dp[0][0] = 0;
    rep3(i, 1, L + 1)
    {
        rep(j, M)
        {
            int ct = 0;
            rep(k, N / L + 1)
            {
                if ((i - 1) + L * k < N)
                    ct += ((M + j) - A[(i - 1) + L * k]) % M;
            }
            rep(k, M)
            {
                if (dp[i - 1][k] == INF)
                    continue;
                dp[i][(j + k) % M] = min(dp[i][(j + k) % M], dp[i - 1][k] + ct);
            }
        }
    }
    int ans = dp[L][0];

    // output
    cout << ans << endl;
}