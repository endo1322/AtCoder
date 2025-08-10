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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        A[i] = a;
    }

    // solve
    int ans = 0;
    V<int> sum_A(N + 1, 0);
    rep(i, N)
    {
        sum_A[i + 1] = sum_A[i] + A[i];
    }
    map<int, int> mp;
    rep(i, N + 1)
    {
        int target = sum_A[i] - K;
        if (mp.count(target))
            ans += mp[target];

        if (mp.count(sum_A[i]))
            mp[sum_A[i]]++;
        else
            mp[sum_A[i]] = 1;
    }

    // output
    cout << ans << endl;
}