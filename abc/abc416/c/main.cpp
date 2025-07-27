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

V<V<int>> iter_p_adic(int p, int n)
{
    V<V<int>> result;
    V<int> digits(n, 0);

    while (true)
    {
        result.push_back(digits);

        int pos = n - 1;
        while (pos >= 0)
        {
            if (digits[pos] + 1 < p)
            {
                digits[pos]++;
                break;
            }
            else
            {
                digits[pos] = 0;
                pos--;
            }
        }
        if (pos < 0)
            break;
    }

    return result;
}

signed main()
{
    // input
    int N, K, X;
    cin >> N >> K >> X;
    V<string> S(N);
    rep(i, N)
    {
        string s;
        cin >> s;
        S[i] = s;
    }

    // solve
    V<string> A;
    auto all_p_adic = iter_p_adic(N, K);
    for (const auto &digits : all_p_adic)
    {
        string s = "";
        for (auto i : digits)
        {
            s += S[i];
        }
        A.push_back(s);
    }
    sort(all(A));
    string ans = A[X - 1];

    // output
    cout << ans << endl;
}