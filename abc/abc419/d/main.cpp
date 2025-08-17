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
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    string T;
    cin >> T;
    V<P<int>> LR(M);
    rep(i, M)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        LR[i] = {l, r};
    }

    // solve
    string ans = "";
    V<int> sum(N + 1, 0);
    rep(i, M)
    {
        int l = LR[i].first;
        int r = LR[i].second;
        sum[l]++;
        sum[r + 1]--;
    }
    rep3(i, 1, N + 1) sum[i] += sum[i - 1];
    rep(i, N)
    {
        if (sum[i] % 2 == 1)
            ans += T[i];
        else
            ans += S[i];
    }

    // output
    cout << ans << endl;
}