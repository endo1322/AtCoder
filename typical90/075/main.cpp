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
const long long INF = 1e18;
const long long MIN_INF = -1e18;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<pair<int, int>> prime_factorize(int N)
{
    vector<pair<int, int>> res;
    for (int a = 2; a * a <= N; ++a)
    {
        if (N % a != 0)
            continue;
        int ex = 0;

        while (N % a == 0)
        {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }

    if (N != 1)
        res.push_back({N, 1});
    return res;
}

signed main()
{
    // input
    int N;
    cin >> N;

    // solve
    int ans = 0;
    vector<pair<int, int>> result = prime_factorize(N);
    int ct = 0;
    for (auto p : result)
        ct += p.second;
    ans = ceil(log2l(ct));

    // output
    cout << ans << endl;
}