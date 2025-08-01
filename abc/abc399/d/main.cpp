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
    int T;
    cin >> T;
    V<V<int>> AB(T);
    V<map<int, V<int>>> AB_map(T);
    rep(i, T)
    {
        int N;
        cin >> N;
        rep(j, N * 2)
        {
            int a;
            cin >> a;
            AB[i].push_back(a);
            AB_map[i][a].push_back(j);
        }
    }

    // solve
    V<int> Ans(T, 0);
    rep(i, T)
    {
        V<int> &ab = AB[i];
        map<int, V<int>> &ab_map = AB_map[i];

        set<int> ng;
        rep(j, ab.size() - 1)
        {
            if (ab[j] == ab[j + 1])
            {
                ng.insert(ab[j]);
            }
        }

        set<P<int>> pairs;
        rep(a1_idx, ab.size() - 1)
        {
            int a1 = ab[a1_idx];
            int b1_idx = a1_idx + 1;
            int b1 = ab[b1_idx];
            if (a1 == b1)
                continue;
            if (ng.count(a1) || ng.count(b1))
                continue;
            int a2_idx = (ab_map[a1][0] == a1_idx) ? ab_map[a1][1] : ab_map[a1][0];
            if (a2_idx - 1 >= 0)
            {
                int b2_idx = a2_idx - 1;
                int b2 = ab[b2_idx];
                if (b2 == b1 && b2_idx != b1_idx)
                {
                    // cout << "3: " << "a: " << a1 << ", b: " << b1 << endl;
                    pairs.insert({min(a1, b1), max(a1, b1)});
                }
            }
            if (a2_idx + 1 < ab.size())
            {
                int b2_idx = a2_idx + 1;
                int b2 = ab[b2_idx];
                if (b2 == b1 && b2_idx != b1_idx)
                {
                    // cout << "4: " << "a: " << a1 << ", b: " << b1 << endl;
                    pairs.insert({min(a1, b1), max(a1, b1)});
                }
            }
        }
        Ans[i] = pairs.size();
    }

    // output
    for (const auto &ans : Ans)
    {
        cout << ans << endl;
    }
}