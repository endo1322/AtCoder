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

bool check753(string S, int N)
{
    bool flag3 = false;
    bool flag5 = false;
    bool flag7 = false;
    for (auto c : S)
    {
        if (c == '3')
            flag3 = true;
        if (c == '5')
            flag5 = true;
        if (c == '7')
            flag7 = true;
    }
    return flag3 && flag5 && flag7;
}

signed main()
{
    // input
    int N;
    cin >> N;

    // solve
    set<int> st;
    string tmp = "";
    auto f = [&](auto f) -> void
    {
        if (stoll(tmp) > N)
            return;
        if (check753(tmp, N))
        {
            st.insert(stoll(tmp));
        }
        for (auto c : {'3', '5', '7'})
        {
            tmp += c;
            f(f);
            tmp.pop_back();
        }
    };
    for (auto c : {'3', '5', '7'})
    {
        tmp += c;
        f(f);
        tmp.pop_back();
    }

    // output
    cout << (int)st.size() << endl;
}