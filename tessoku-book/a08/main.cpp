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
template<class T> using P = pair<T, T>;
const long long INF = 1e18;
const long long MIN_INF = -1e18;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<int> culc_p(int N) {
    vector<bool> isP(N, true);
    vector<int> P;
    isP[0] = isP[1] = false;
    rep3 (i, 2, N) {
        if (!isP[i]) continue;
        P.push_back(i);
        for (int j = 1; i * j < N; j++) {
            isP[i*j] = false;
        }
    }
    return P;
}

signed main() {
    // input
    int H, W; cin >> H >> W;
    map<P<int>, int> A;
    rep (i, H) {
        rep (j, W) {
            int x;
            cin >> x;
            A[{i, j}] = x;
        }   
    }

    // solve
    map<P<int>, int> sum;
    rep (i, H) {
        rep (j, W) {
            if (j == 0) sum[{i, j}] = A[{i, j}];
            else sum[{i, j}] = A[{i, j}] + sum[{i, j-1}];
        }
    }
    rep (j, W) {
        rep (i, H) {
            if (i == 0) continue;
            else sum[{i, j}] += sum[{i-1, j}];
        }
    }
    int Q; cin >> Q;
    vector<int> ans(Q);
    rep (i, Q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        int tmp = 0;
        if (a > 0 && b > 0) tmp = sum[{c, b-1}] + sum[{a-1, d}] - sum[{a-1, b-1}];
        else if (a > 0) tmp = sum[{a-1, d}];
        else if (b > 0) tmp = sum[{c, b-1}];
        ans[i] = sum[{c, d}] - tmp;
    }

    // output
    rep (i, Q) {
        cout << ans[i] << endl;
    }
}