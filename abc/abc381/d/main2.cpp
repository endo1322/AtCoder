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
    vector<int> A(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        A[i] = a;
    }

    // solve
    int i = 0;
    V<int> AA;
    while (i < N)
    {
        int j = 1;
        while (i + j < N && A[i + j] == A[i])
            j++;

        if (j == 1)
            AA.push_back(-1);
        else if (j == 2)
            AA.push_back(A[i]);
        else
        {
            AA.push_back(A[i]);
            AA.push_back(-1);
            AA.push_back(A[i]);
        }
        i += j;
    }
    int ans = 0;
    queue<int> que;
    set<int> st;
    for (int a : AA)
    {
        if (a == -1)
        {
            que = queue<int>();
            st.clear();
        }
        else if (st.count(a) == 0)
        {
            que.push(a);
            st.insert(a);
            ans = max(ans, (int)que.size());
        }
        else
        {
            while (!que.empty() && que.front() != a)
            {
                st.erase(que.front());
                que.pop();
            }
            if (!que.empty())
                que.pop();
            que.push(a);
            ans = max(ans, (int)que.size());
        }
    }
    ans = max(ans, (int)que.size());
    ans *= 2;

    // output
    cout << ans << endl;
}