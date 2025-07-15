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

void printStack(std::stack<int> s)
{
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}
signed main()
{
    // input
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N)
    {
        cin >> H[i];
    }

    // solve
    stack<int> st;
    V<int> Ans(N);
    rrep(i, N)
    {
        Ans[i] = st.size();
        if (st.empty())
        {
            st.push(H[i]);
            continue;
        }
        while (!st.empty() && H[i] > st.top())
        {
            st.pop();
        }
        st.push(H[i]);
    }

    // output
    rep(i, N)
    {
        cout << Ans[i];
        if (i < N - 1)
            cout << " ";
        else
            cout << endl;
    }
}
