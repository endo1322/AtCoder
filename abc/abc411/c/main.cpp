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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(Q);
    rep(i, Q)
    {
        int a;
        cin >> a;
        a--;
        A[i] = a;
    }

    // solve
    V<int> ans(Q, 0);
    V<bool> M(N, false);
    int sum = 0;
    rep(i, Q)
    {
        if (M[A[i]])
        {
            M[A[i]] = false;
            if (A[i] - 1 >= 0 && A[i] + 1 < N && M[A[i] - 1] && M[A[i] + 1])
            {
                sum++;
                ans[i] = sum;
            }
            else if (A[i] - 1 >= 0 && M[A[i] - 1])
            {
                ans[i] = sum;
            }
            else if (A[i] + 1 < N && M[A[i] + 1])
            {
                ans[i] = sum;
            }
            else
            {
                sum--;
                ans[i] = sum;
            }
        }
        else
        {
            M[A[i]] = true;
            if (A[i] - 1 >= 0 && A[i] + 1 < N && M[A[i] - 1] && M[A[i] + 1])
            {
                sum--;
                ans[i] = sum;
            }
            else if (A[i] - 1 >= 0 && M[A[i] - 1])
            {
                ans[i] = sum;
            }
            else if (A[i] + 1 < N && M[A[i] + 1])
            {
                ans[i] = sum;
            }
            else
            {
                sum++;
                ans[i] = sum;
            }
        }
    }

    // output
    rep(i, Q)
    {
        cout << ans[i] << endl;
    }
}