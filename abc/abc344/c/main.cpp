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
    int N, M, L, Q;
    cin >> N;
    V<int> A(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    cin >> M;
    V<int> B(M);
    rep(i, M)
    {
        int b;
        cin >> b;
        B[i] = b;
    }
    cin >> L;
    V<int> C(L);
    rep(i, L)
    {
        int c;
        cin >> c;
        C[i] = c;
    }
    cin >> Q;
    V<int> X(Q);
    rep(i, Q)
    {
        int d;
        cin >> d;
        X[i] = d;
    }

    // solve
    V<string> Ans(Q);
    set<int> st;
    rep(i, N)
    {
        rep(j, M)
        {
            rep(k, L)
            {
                st.insert(A[i] + B[j] + C[k]);
            }
        }
    }
    rep(i, Q)
    {
        if (st.count(X[i]))
            Ans[i] = "Yes";
        else
            Ans[i] = "No";
    }

    // output
    for (auto ans : Ans)
    {
        cout << ans << endl;
    }
}