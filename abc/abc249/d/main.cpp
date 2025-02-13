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
    int N; cin >> N;
    map<int, int> mp;
    rep (i, N) {
        int a;
        cin >> a;
        if (mp.count(a)) mp[a]++;
        else mp[a] = 1;
    }

    // solve
    int ans = 0;
    set<tuple<int>> st;
    for (auto [key, ct]: mp) {
        for (int i = 1; i <= sqrt(key); i++) {
            int tmp = 0;
            if (key % i != 0) continue;
            int a = i;
            int b = key / i;
            if (mp.count(a) == 0 || mp.count(b) == 0) continue;
            int a_ct = mp[a];
            int b_ct = mp[b];
            
            tmp += a_ct * b_ct * ct;
            if (a != b) {
                tmp *= 2;
            }

            ans += tmp;
        }
    }

    // output
    cout << ans << endl;
}