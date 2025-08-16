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

int convert_block_x1(int x, int y)
{
    if (y % 2 == 0)
        return x / 2;
    else
        return (x + 1) / 2;
}

int convert_block_x2(int x, int y)
{
    if (y % 2 == 0)
        return x / 2;
    else
        return (x - 1) / 2;
}

int convert_block_y(int y)
{
    return y;
}

signed main()
{
    // input
    int Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    // solve
    int Syb = convert_block_y(Sy);
    int Tyb = convert_block_y(Ty);
    int dy = abs(Syb - Tyb);

    int Sxb1 = convert_block_x1(Sx, Sy);
    int Txb1 = convert_block_x1(Tx, Ty);
    int dx1 = max(abs(Sxb1 - Txb1) - dy / 2, 0LL);

    int Sxb2 = convert_block_x2(Sx, Sy);
    int Txb2 = convert_block_x2(Tx, Ty);
    int dx2 = max(abs(Sxb2 - Txb2) - dy / 2, 0LL);

    int ans = min(dx1, dx2) + dy;

    // output
    cout << ans << endl;
}