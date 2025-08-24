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

string to_base(int n, int base)
{
    if (n == 0)
        return "0";
    string res;
    while (n > 0)
    {
        res += '0' + (n % base);
        n /= base;
    }
    reverse(all(res));
    return res;
}

signed main()
{
    // input
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    V<int> K(Q);
    rep(i, Q)
    {
        cin >> K[i];
        K[i]--;
    }

    // solve
    V<char> Ans(Q);
    rep(i, Q)
    {
        int k = K[i];
        int N = S.size();
        int idx = k % N;
        int e = k / N;
        string b = to_base(e, 2);
        int ct = 0;
        for (char c : b)
            if (c == '1')
                ct++;

        if (ct % 2 == 0)
            Ans[i] = S[idx];
        else
        {
            if (isupper(S[idx]))
                Ans[i] = tolower(S[idx]);
            else
                Ans[i] = toupper(S[idx]);
        }
    }

    // output
    rep(i, Q)
    {
        cout << Ans[i];
        if (i != Q - 1)
            cout << ' ';
        else
            cout << endl;
    }
}