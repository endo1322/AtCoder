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
    int N, S;
    cin >> N >> S;
    vector<P<int>> AB(N);
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        AB[i] = {a, b};
    }

    // solve
    V<V<bool>> dp(N + 1, V<bool>(10e4 + 1, false));
    dp[0][0] = true;
    rep3(i, 1, N + 1)
    {
        rep(j, 10e4 + 1)
        {
            if (dp[i - 1][j])
            {
                auto [a, b] = AB[i - 1];
                dp[i][j + a] = true;
                dp[i][j + b] = true;
            }
        }
    }

    if (dp[N][S])
    {
        cout << "Yes" << endl;
        string backtrack;
        int j = S;
        rrep(i, N)
        {
            auto [a, b] = AB[i];
            if (j >= a && dp[i][j - a])
            {
                backtrack += 'H';
                j -= a;
            }
            else
            {
                backtrack += 'T';
                j -= b;
            }
        }
        reverse(all(backtrack));
        cout << backtrack << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}