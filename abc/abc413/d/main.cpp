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
    V<V<int>> A(T);
    rep(i, T)
    {
        int N;
        cin >> N;
        rep(j, N)
        {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    // solve
    V<string> Ans(T);
    rep(i, T)
    {
        if (A[i].size() < 3)
        {
            Ans[i] = "Yes";
            continue;
        }
        sort(all(A[i]), [](int x, int y)
             { return abs(x) < abs(y); });

        bool ok = true;

        rep3(j, 1, A[i].size() - 1)
        {
            int bb = A[i][j] * A[i][j];
            int ac = A[i][j - 1] * A[i][j + 1];
            if (bb != ac)
            {
                ok = false;
                break;
            }
        }

        if (abs(A[i].back()) - abs(A[i][0]) < 1)
        {
            int neg = 0, pos = 0;
            rep(j, A[i].size())
            {
                if (A[i][j] < 0)
                    neg++;
                else if (A[i][j] > 0)
                    pos++;
            }
            if (abs(neg - pos) <= 1)
            {
                ok = true;
            }
        }

        Ans[i] = ok ? "Yes" : "No";
    }

    // output
    for (const auto &ans : Ans)
    {
        cout << ans << endl;
    }
}