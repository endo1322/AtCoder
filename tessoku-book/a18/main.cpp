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

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

signed main() {
    // input
    int N, S; cin >> N >> S;
    vector<int> A(N);
    rep (i, N) {
        int a;
        cin >> a;
        A[i] = a;
    }

    // solve
    string ans = "No";
    vector<vector<bool>> dp(N+1, vector<bool>(S+1));
    rep (i, N+1) {
        rep (j, S+1) {
            if (i == 0 && j == 0) dp[i][j] = true;
            else if (i == 0 && j != 0) dp[i][j] = false;
            else if (j < A[i-1] && dp[i-1][j]) dp[i][j] = true;
            else if (j >= A[i-1] && (dp[i-1][j] || dp[i-1][j - A[i-1]])) dp[i][j] = true;
            else dp[i][j] = false;
        }
    }
    if (dp[N][S]) ans = "Yes";
    
    // output
    cout << ans << endl;
}