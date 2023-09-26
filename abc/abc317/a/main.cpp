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

signed main() {
    // input
    int N, H, X; cin >> N >> H >> X;
    vector<int> P(N);
    rep (i, N) {
        cin >> P.at(i);
    }

    // solve
    int mn = 1000;
    int ans = 0;
    rep(i, N) {
        if (H + P[i] >= X && mn > P[i]) {
            mn = P[i];
            ans = i + 1;
        }
    }

    // output
    cout << ans << endl;
}