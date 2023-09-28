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
    int N; cin >> N;
    vector<int> DP(2, 0);
    rep (i, N) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
            DP[0] = max(DP[0], max(y, max(y + DP[0], y + DP[1])));
        } else {
            DP[1] = max(DP[1], max(y, y + DP[0]));
        }
    }

    // output
    cout << max(DP[0], DP[1]) << endl;
}