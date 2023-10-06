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
    int N; cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    rep3 (i, 1, N) {
        int a;
        cin >> a;
        A[i] = a;
    }
    rep3 (i, 2, N) {
        int a;
        cin >> a;
        B[i] = a;
    }

    // solve
    vector<int> dp(N);
    dp[0] = 0;
    dp[1] = A[1];
    rep3 (i, 2, N) {
        dp[i] = min(dp[i-2] + B[i] , dp[i-1] + A[i]);
    }

    vector<int> ans;
    int i = N-1;
    ans.push_back(i+1);
    while (i > 0) {
        if (dp[i] == dp[i-1] + A[i]) {
            i -= 1;   
        } else {
            i -= 2;
        }
        ans.push_back(i+1);
    }
    reverse(all(ans));

    // output
    cout << ans.size() << endl;
    rep (i, ans.size()) {
        cout << ans[i];
        if (i == ans.size() - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}