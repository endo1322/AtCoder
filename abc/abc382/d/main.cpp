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

    // solve
    V<V<int>> Ans;
    auto f = [&](auto f, int a, int cnt, V<int> &tmp) -> void
    {
        if (cnt == N)
        {
            Ans.push_back(tmp);
            return;
        }

        rep3(i, a + 10, M + 1)
        {
            if (a + (N - cnt) * 10 > M)
                return;
            tmp.push_back(i);
            f(f, i, cnt + 1, tmp);
            tmp.pop_back();
        }
    };
    rep3(i, 1, M + 1)
    {
        V<int> tmp;
        tmp.push_back(i);
        f(f, i, 1, tmp);
        tmp.pop_back();
    }

    // output
    cout << Ans.size() << endl;
    for (auto &v : Ans)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}