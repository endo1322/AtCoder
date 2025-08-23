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

vector<int> culc_p(int N)
{
    vector<bool> isP(N + 1, true);
    vector<int> P;
    isP[0] = isP[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (!isP[i])
            continue;
        for (int j = i * i; j <= N; j += i)
            isP[j] = false;
    }
    rep3(i, 2, N + 1) if (isP[i]) P.push_back(i);
    return P;
}

signed main()
{
    // input
    int N;
    cin >> N;

    // solve
    int ans = 0;
    V<int> P = culc_p(1e6);
    V<int> D;
    rep(i, P.size())
    {
        if (powl(P[i], 4) > N)
            break;
        rep3(j, i + 1, P.size())
        {
            int d = powl(P[i], 2) * powl(P[j], 2);
            if (d > N)
                break;
            ans++;
        }
    }
    rep(i, P.size())
    {
        if (powl(P[i], 8) > N)
            break;
        ans++;
    }

    // output
    cout << ans << endl;
}