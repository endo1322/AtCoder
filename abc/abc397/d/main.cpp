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

int sol(int a, int b, int c)
{
    int l = 0, r = 600000001;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (a * mid * mid + b * mid + c <= 0)
            l = mid;
        else
            r = mid;
    }
    if (a * l * l + b * l + c == 0)
        return l;
    return -1;
}

signed main()
{
    // input
    int N;
    cin >> N;

    // solve
    int ans = -1;
    rep3(d, 1, 1e6)
    {
        // overflow
        // int a = 3 * d;
        // int b = 3 * d * d;
        // int c = d * d * d - N;

        if (N % d != 0)
            continue;

        int m = N / d;
        int dP2 = d * d;
        int a = 3;
        int b = 3 * d;
        int c = dP2 - m;

        int y = sol(a, b, c);

        int x = d + y;
        if (x * x * x - y * y * y == N && x > 0 && y > 0)
        {
            cout << x << ' ' << y << endl;
            return 0;
        }
    }

    // output
    cout << ans << endl;
}