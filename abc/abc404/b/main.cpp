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
    int N;
    cin >> N;
    vector<vector<char>> S1(N, vector<char>(N));
    vector<vector<char>> S2(N, vector<char>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> S1[i][j];
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            cin >> S2[i][j];
        }
    }

    // solve
    int ans = INF;
    vector<vector<char>> S1_COPY(N, vector<char>(N));
    rep(i, N)
    {
        rep(j, N)
        {
            S1_COPY[i][j] = S1[i][j];
        }
    }
    rep(i, N)
    {
        rep(j, N)
        {
            S1[i][j] = S1_COPY[i][j];
        }
    }
    rep(i, 4)
    {
        int ct = 0;
        rep(j, N)
        {
            rep(k, N)
            {
                if (S1[j][k] != S2[j][k])
                {
                    ct++;
                }
            }
        }
        ans = min(ans, ct + i);
        rep(j, N)
        {
            rep(k, N)
            {
                S1_COPY[j][k] = S1[N - k - 1][j];
            }
        }
        rep(j, N)
        {
            rep(k, N)
            {
                S1[j][k] = S1_COPY[j][k];
            }
        }
    }

    // output
    cout << ans << endl;
}