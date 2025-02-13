#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define rep3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define rrep(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define rrep3(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
#define int long long
#define ll long long
#define double long double
using mint = modint998244353;
template<class T> using V = vector<T>;
template<class T> using P = pair<T, T>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T,V<T>,greater<T>>;
const long long INF = LLONG_MAX;
const long long MIN_INF = LLONG_MIN;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

signed main() {
    // input
    int N, K; cin >> N >> K;
    vector<string> S(N);
    rep (i, N) {
        string s;
        cin >> s;
        S[i] = s;
    }

    // solve
    int ans = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        map<char, int> mp;
        int tmp = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) {
                for (auto s: S[i]) {
                    if (mp.count(s)) mp[s]++;
                    else mp[s] = 1;
                }
            }
        }

        for (auto [key, ct]: mp) {
            if (ct == K) tmp++;
        }
        ans = max(ans, tmp);
    }

    // output
    cout << ans << endl;
}