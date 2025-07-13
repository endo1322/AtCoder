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

bool check(string s)
{
    int len = s.size();
    rep(i, len / 2)
    {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
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
    bool skip_1 = false;
    bool skip_2 = false;
    rep3(i, 1, 100000000)
    {
        string s = to_string(i);
        string reversed_s_1 = s.substr(0, s.size() - 1);
        reversed_s_1 = string(reversed_s_1.rbegin(), reversed_s_1.rend());
        string tmp1_str = s + reversed_s_1;
        int tmp1 = stoll(tmp1_str);
        if (tmp1 > N)
            skip_1 = true;
        if (!skip_1)
        {
            string tmp1_base_A = to_base_str(tmp1, A);
            if (check(tmp1_base_A))
                ans += tmp1;
        }

        string reversed_s_2 = string(s.rbegin(), s.rend());
        string tmp2_str = s + reversed_s_2;
        int tmp2 = stoll(tmp2_str);
        if (tmp2 > N)
            skip_2 = true;
        if (!skip_2)
        {
            string tmp2_base_A = to_base_str(tmp2, A);
            if (check(tmp2_base_A))
                ans += tmp2;
        }

        if (skip_1 && skip_2)
            break;
    }

    // output
    cout << ans << endl;
}