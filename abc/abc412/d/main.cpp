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
    V<V<bool>> Graph(N, V<bool>(N, false));
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b)
            swap(a, b);
        Graph[a][b] = true;
    }

    // solve
    int ans = INF;
    V<int> perm(N);
    rep(i, N) perm[i] = i;
    do
    {
        // cycle * 1
        V<V<bool>> cycle1(N, V<bool>(N, false));
        rep(i, N)
        {
            int a = perm[i];
            int b = perm[(i + 1) % N];
            if (a > b)
                swap(a, b);
            cycle1[a][b] = true;
        }
        int cnt = 0;
        rep(i, N) rep(j, N) if (Graph[i][j] != cycle1[i][j]) cnt++;
        ans = min(ans, cnt);

        // cycle * 2
        rep3(d, 3, N - 3 + 1)
        {
            V<V<bool>> cycle2(N, V<bool>(N, false));
            rep(i, d)
            {
                int a = perm[i];
                int b = perm[(i + 1) % d];
                if (a > b)
                    swap(a, b);
                cycle2[a][b] = true;
            }
            rep(i, N - d)
            {
                int a = perm[d + i];
                int b = perm[(i + 1) % (N - d) + d];
                if (a > b)
                    swap(a, b);
                cycle2[a][b] = true;
            }
            cnt = 0;
            rep(i, N) rep(j, N) if (Graph[i][j] != cycle2[i][j]) cnt++;
            ans = min(ans, cnt);
        }
    } while (next_permutation(all(perm)));

    // output
    cout << ans << endl;
}