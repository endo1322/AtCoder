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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H) rep(j, W) cin >> B[i][j];

    // solve
    int ans_ct = 0;
    rep(i, H - 1)
    {
        rep(j, W - 1)
        {
            int diff = A[i][j] - B[i][j];
            if (diff == 0)
                continue;
            ans_ct += abs(diff);
            rep(k, 2) rep(l, 2)
            {
                A[i + k][j + l] -= diff;
            }
        }
    }

    rep(i, H) rep(j, W) if (A[i][j] != B[i][j])
    {
        cout << "No" << endl;
        return 0;
    }

    // output
    cout << "Yes" << endl;
    cout << ans_ct << endl;
}