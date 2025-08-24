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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<int> B(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    rep(i, N)
    {
        int b;
        cin >> b;
        B[i] = b;
    }
    V<pair<int, P<int>>> queries(Q);
    rep(i, Q)
    {
        char c;
        int x, v;
        cin >> c >> x >> v;
        queries[i] = {c, {x, v}};
    }

    // solve
    V<int> Ans(Q);
    V<int> min_sum(N, 0);
    int sum = 0;
    rep(i, N)
    {
        min_sum[i] = min(A[i], B[i]);
        sum += min_sum[i];
    }
    // cout << sum << endl;
    rep(i, Q)
    {
        char c = queries[i].first;
        int x = queries[i].second.first - 1;
        int v = queries[i].second.second;
        if (c == 'A')
        {
            sum -= min_sum[x];
            A[x] = v;
            int min_prev = min_sum[x];
            min_sum[x] = min(A[x], B[x]);
            sum += min_sum[x];
            // int min_prev = min_sum[x];
            // int min_tmp = min(v, B[x]);
            // Ans[i] = sum - min_prev + min_tmp;
        }
        else
        {
            sum -= min_sum[x];
            B[x] = v;
            int min_prev = min_sum[x];
            min_sum[x] = min(A[x], B[x]);
            sum += min_sum[x];
            // int min_prev = min_sum[x];
            // int min_tmp = min(A[x], v);
            // Ans[i] = sum - min_prev + min_tmp;
        }
        Ans[i] = sum;
    }

    // output
    for (auto a : Ans)
    {
        cout << a << endl;
    }
}