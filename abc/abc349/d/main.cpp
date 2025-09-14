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

pair<pair<int, int>, int> f(int l, int r, int e)
{
    while (e >= 0)
    {
        int pow2 = 1LL << e;
        int q = r / pow2;
        if (!(l <= pow2 * (q - 1) && pow2 * q <= r))
            e--;
        else
            return {{pow2 * (q - 1), pow2 * q}, e};
    }
}

signed main()
{
    // input
    int L, R;
    cin >> L >> R;

    // solve
    V<P<int>> Ans;
    int diff = R - L;
    int e_max = log2l(diff);
    auto [lr, e] = f(L, R, e_max);
    Ans.push_back(lr);
    int lr_l = lr.first;
    int lr_r = lr.second;
    int e_l = e;
    int e_r = e;
    while (e_l >= 0 && lr_l != L)
    {
        auto [lr, e_l_new] = f(L, lr_l, e_l);
        Ans.push_back(lr);
        e_l = e_l_new;
        lr_l = lr.first;
    }
    while (e_r >= 0 && lr_r != R)
    {
        auto [lr, e_r_new] = f(lr_r, R, e_r);
        Ans.push_back(lr);
        e_r = e_r_new;
        lr_r = lr.second;
    }
    sort(all(Ans));

    // output
    cout << Ans.size() << endl;
    for (auto [l, r] : Ans)
    {
        cout << l << " " << r << endl;
    }
}