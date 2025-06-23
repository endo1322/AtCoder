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
    V<set<int>> A(M);
    map<int, V<int>> mp;
    rep(i, M)
    {
        int K;
        cin >> K;
        rep(j, K)
        {
            int a;
            cin >> a;
            A[i].insert(a - 1);
            mp[a - 1].push_back(i);
        }
    }
    V<int> B(N);
    rep(i, N)
    {
        cin >> B[i];
        B[i]--;
    }

    // solve
    V<int> Ans(N, 0);
    int ct = 0;
    rep(i, N)
    {
        int b = B[i];
        for (int idx : mp[b])
        {
            A[idx].erase(b);
            if (A[idx].empty())
                ct++;
        }
        Ans[i] = ct;
    }

    // output
    rep(i, N)
    {
        cout << Ans[i] << endl;
    }
}