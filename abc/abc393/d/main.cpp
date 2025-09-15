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

int sum_arithmetic(int n)
{
    return n * (n + 1) / 2;
}

signed main()
{
    // input
    int N;
    cin >> N;
    string S;
    cin >> S;

    // solve
    int ans = INF;
    V<int> one_idx;
    rep(i, N) if (S[i] == '1') one_idx.push_back(i);
    V<int> sum(one_idx.size() + 1, 0);
    rep3(i, 1, one_idx.size() + 1)
        sum[i] = sum[i - 1] + one_idx[i - 1];

    rep(i, one_idx.size())
    {
        int r_num = one_idx.size() - (i + 1);
        int r_sum = sum[one_idx.size()] - sum[i + 1];
        int sum_to_r_num = sum_arithmetic(r_num);

        int l_num = i;
        int l_sum = one_idx[i] * l_num;
        int sum_to_l_num = sum_arithmetic(l_num);

        int cost = (l_sum - sum[i] - sum_to_l_num) + (r_sum - one_idx[i] * r_num - sum_to_r_num);
        ans = min(ans, cost);
    }

    // output
    cout << ans << endl;
}