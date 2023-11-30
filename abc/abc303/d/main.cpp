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
    int X, Y, Z; cin >> X >> Y >> Z;
    string S; cin >> S;

    // solve
    vector<vector<int>> dp(S.size(), vector<int>(2, 0));
    rep (i, S.size()) {
        if (i == 0) {
            if (S[i] == 'a') {
                dp[0][0] = X;
                dp[0][1] = Z + Y;
            } else {
                dp[0][0] = Y;
                dp[0][1] = Z + X;
            }
        } else{
            if (S[i] == 'a') {
                dp[i][0] = min(dp[i-1][0] + X, dp[i-1][1] + Z + X);
                dp[i][1] = min(dp[i-1][0] + Z + Y, dp[i-1][1] + Y);
            } else {
                dp[i][0] = min(dp[i-1][0] + Y, dp[i-1][1] + Z + Y);
                dp[i][1] = min(dp[i-1][0] + Z + X, dp[i-1][1] + X);
            }
        }
    }

    int ans = min(dp[S.size()-1][0], dp[S.size()-1][1]);

    // output
    cout << ans << endl;
}