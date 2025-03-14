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
    vector<int> A(N);
    rep (i, N) {
        int a;
        cin >> a;
        A[i] = a;
    }
    vector<int> sum(N, 0);
    sum[0] = A[0] - 1;
    int prev = A[0];
    rep3 (i, 1, N) {
        sum[i] = sum[i-1] + (A[i] - prev - 1);
        prev = A[i];
    }
    rep (i, Q) {
        int K; cin >> K;
        int idx = lower_bound(all(sum), K) - sum.begin();
        int ans;
        if (idx == 0) {
            ans = K;
        } else {
            ans = A[idx-1] + (K - sum[idx-1]);
        }
        cout << ans << endl;
    }
}