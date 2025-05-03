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
    vector<int> C(N);
    vector<vector<int>> A(M);
    rep(i, N)
    {
        int c;
        cin >> c;
        C[i] = c;
    }
    rep(i, M)
    {
        int K;
        cin >> K;
        rep(j, K)
        {
            int a;
            cin >> a;
            a--;
            A[i].push_back(a);
        }
    }

    // solve
    int ans = INF;
    rep(i, pow(3, N))
    {
        vector<int> B(N);

        int p3 = 1;
        rep(j, N)
        {
            B[j] = (i / p3) % 3;
            p3 *= 3;
        }

        int tmp = 0;
        vector<int> ct(M, 0);
        rep(j, N)
        {
            tmp += C[j] * B[j];
            rep(k, M)
            {
                if (find(all(A[k]), j) != A[k].end())
                {
                    ct[k] += B[j];
                }
            }
        }

        bool flag = true;
        rep(j, M)
        {
            if (ct[j] < 2)
                flag = false;
        }

        if (flag)
            ans = min(ans, tmp);
    }

    cout << ans << endl;
}