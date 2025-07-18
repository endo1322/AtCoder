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
    int N, Q; cin >> N >> Q;
    V<int> h2idx(N);
    V<int> idx2s(N);
    V<int> s2idx(N);
    rep (i, N) h2idx[i] = i;
    rep (i, N) idx2s[i] = i;
    rep (i, N) s2idx[i] = i;
    rep (i, Q) {
        int q; cin >> q;
        if (q == 1) {
            int a, b; cin >> a >> b;
            a--; b--;
            int h = a;
            int s = b;
            h2idx[h] = s2idx[s];
        } else if (q == 2) {
            int a, b; cin >> a >> b;
            a--; b--;
            int s_a = a;
            int s_b = b;
            int idx_a = a;
            int idx_b = b;
            swap(s2idx[s_a], s2idx[s_b]);
            idx2s[s2idx[s_a]] = s_a;
            idx2s[s2idx[s_b]] = s_b;
        } else {
            int a; cin >> a;
            a--;
            int h = a;
            int s = a;
            int idx = a;
            s = idx2s[h2idx[h]];
            cout << s+1 << endl;
        }
    }
}