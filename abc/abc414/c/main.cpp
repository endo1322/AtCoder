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

bool is_palindrome(string s)
{
    string r_s = s;
    reverse(r_s.begin(), r_s.end());
    return s == r_s;
}

string to_base_str(int n, int base)
{
    if (n == 0)
        return "0";
    string res;
    while (n > 0)
    {
        res += '0' + (n % base);
        n /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

signed main()
{
    // input
    int A, N;
    cin >> A >> N;

    // solve
    int ans = 0;
    auto check = [&](int x) -> bool
    {
        return x <= N && is_palindrome(to_base_str(x, A));
    };

    bool skip_1 = false;
    bool skip_2 = false;
    rep3(i, 1, 10e6)
    {
        string s = to_string(i);
        string r_s = s;
        reverse(r_s.begin(), r_s.end());
        s += r_s;
        int s_ll = stoll(s);
        if (s_ll > N)
            skip_1 = true;
        if (!skip_1 && check(s_ll))
            ans += s_ll;

        s.erase(s.begin() + (s.size() / 2));
        s_ll = stoll(s);
        if (s_ll > N)
            skip_2 = true;
        if (!skip_2 && check(s_ll))
            ans += s_ll;

        if (skip_1 && skip_2)
            break;
    }

    // output
    cout << ans << endl;
}