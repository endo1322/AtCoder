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

int binary_search(int key, vector<int> &a) {
    int ng = -1;
    int ok = (int)a.size();

    auto isOK = [&](int index) -> bool {
        return a[index] >= key;
    };

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<int> B(N);
    vector<int> W;
    rep (i, N) {
        int a;
        cin >> a;
        B[i] = a;
    }
    rep (i, M) {
        int a;
        cin >> a;
        if (a < 0) continue;
        W.push_back(a);
    }

    // solve
    int ans = MIN_INF;
    sort(rall(B));
    sort(rall(W));

    vector<int> sum_B(N+1, 0);
    rep (i, N) sum_B[i+1] = sum_B[i] + B[i];
    int W_size = W.size();
    vector<int> sum_W(W_size+1, 0);
    rep (i, W_size) sum_W[i+1] = sum_W[i] + W[i];

    rep (i, N+1) {
        int tmp = 0;
        tmp += sum_B[i];
        int idx_w = min(i, W_size);
        tmp += sum_W[idx_w];
        ans = max(ans, tmp);
    }

    // output
    cout << ans << endl;
}