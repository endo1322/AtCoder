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
    vector<int> A(N);
    vector<int> B(M);
    rep(i, N)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    rep(i, M)
    {
        int b;
        cin >> b;
        B[i] = b;
    }

    // solve
    V<int> Ans;
    sort(all(B));
    int idx_a = 0;
    int idx_b = 0;
    while (idx_a < N && idx_b < M)
    {
        if (A[idx_a] < B[idx_b])
        {
            Ans.push_back(A[idx_a]);
            idx_a++;
        }
        else if (A[idx_a] > B[idx_b])
        {
            idx_b++;
        }
        else
        {
            idx_a++;
            idx_b++;
        }
    }
    rep3(i, idx_a, N) Ans.push_back(A[i]);

    // output
    rep(i, Ans.size())
    {
        cout << Ans[i];
        if (i < Ans.size() - 1)
            cout << " ";
    }
    cout << endl;
}