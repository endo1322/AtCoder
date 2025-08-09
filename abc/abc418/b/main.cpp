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

    // solve
    double ans = 0;
    int size = S.size();
    rep(i, size)
    {
        if (S[i] != 't')
            continue;
        rep3(j, i, size)
        {
            if (S[j] != 't')
                continue;
            int t_len = j - i + 1;
            if (t_len < 3)
                continue;
            int t_ct = 0;
            rep(k, t_len)
            {
                if (S[i + k] == 't')
                    t_ct++;
            }
            double tmp = (t_ct - 2) / (double)(t_len - 2);
            ans = max(ans, tmp);
        }
    }

    // output
    cout << fixed << setprecision(15) << ans << endl;
}