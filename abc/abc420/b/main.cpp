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
    V<string> S(N);
    rep(i, N)
    {
        string s;
        cin >> s;
        S[i] = s;
    }

    // solve
    V<int> ans;
    V<int> cnt(N, 0);
    rep(i, M)
    {
        int ct_0 = 0;
        int ct_1 = 0;
        rep(j, N)
        {
            if (S[j][i] == '0')
                ct_0++;
            else
                ct_1++;
        }
        rep(j, N)
        {
            if (ct_0 > ct_1)
            {
                if (S[j][i] == '1')
                    cnt[j]++;
            }
            else if (ct_0 < ct_1)
            {
                if (S[j][i] == '0')
                    cnt[j]++;
            }
            else
            {
                cnt[j]++;
            }
        }
    }
    // for (auto s : S)
    // {
    //     rep(i, M) if (s[i] == '1') cnt[i]++;
    // }
    int mx = 0;
    rep(i, N)
    {
        mx = max(mx, cnt[i]);
    }
    rep(i, N)
    {
        if (cnt[i] == mx)
            ans.push_back(i + 1);
    }

    // output
    for (auto a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}