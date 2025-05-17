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
    int H, W, N;
    cin >> H >> W >> N;
    vector<set<int>> X(H), Y(W);
    rep(i, N)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        X[x].insert(y);
        Y[y].insert(x);
    }
    int Q;
    cin >> Q;
    vector<int> ans(Q);
    rep(i, Q)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int x;
            cin >> x;
            x--;
            ans[i] = X[x].size();
            for (int y : X[x])
            {
                Y[y].erase(x);
            }
            X[x].clear();
        }
        else
        {
            int y;
            cin >> y;
            y--;
            ans[i] = Y[y].size();
            for (int x : Y[y])
            {
                X[x].erase(y);
            }
            Y[y].clear();
        }
    }

    // output
    rep(i, Q)
    {
        cout << ans[i] << endl;
    }
}