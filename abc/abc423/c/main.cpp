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
    int N, R;
    cin >> N >> R;
    vector<int> L(N);
    int first = -1;
    int last = -1;
    rep(i, N)
    {
        int l;
        cin >> l;
        L[i] = l;
        if (l == 0)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    // solve
    if (first == -1)
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    bool go_left = true;
    stack<int> st;
    int d = 0;
    if (first < R)
    {
        rep(i, R - first)
        {
            if (L[R - i - 1] == 0)
                ans++;
            else
                ans += 2;
        }
    }
    // cout << "ans: " << ans << endl;
    // cout << "first: " << first << ", last: " << last << endl;
    if (last >= R)
    {
        rep(i, last - R + 1)
        {
            if (L[R + i] == 0)
                ans++;
            else
                ans += 2;
        }
    }
    // cout << "ans: " << ans << endl;

    // output
    cout << ans << endl;
}