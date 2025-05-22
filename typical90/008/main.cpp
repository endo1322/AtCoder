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
using mint = modint1000000007;
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

V<char> Atcoder = {'a', 't', 'c', 'o', 'd', 'e', 'r'};

signed main()
{
    // input
    int N;
    cin >> N;
    string S;
    cin >> S;

    // solve
    V<V<mint>> dp(Atcoder.size() + 1, V<mint>(N + 1, 0));
    rep(i, N + 1) dp[0][i] = 1;
    rep3(i, 1, Atcoder.size() + 1)
    {
        char c = Atcoder[i - 1];
        rep3(j, 1, N + 1)
        {
            char c_s = S[j - 1];
            if (c == c_s)
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    // output
    cout << dp[Atcoder.size()][N].val() << endl;
}