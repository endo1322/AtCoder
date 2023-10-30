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

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

signed main() {
    // input
    int N; cin >> N;
    vector<P<int>> PA(N);
    rep (i, N) {
        int p, a;
        cin >> p >> a;
        PA[i].first = p - 1;
        PA[i].second = a;
    }

    // solve
    vector<vector<int>> dp(N, vector<int> (N));
    dp[0][N-1] = 0;
    rep (i, N) {
        rrep (j, N) {
            if (i == 0 && j == N-1) continue;
            if (i == 0) {
                if (PA[j+1].first < j+1) dp[i][j] = dp[i][j+1] + PA[j+1].second;
                else dp[i][j] = dp[i][j+1];
            } else if (j == N-1) {
                if (PA[i-1].first > i-1) dp[i][j] = dp[i-1][j] + PA[i-1].second;
                else dp[i][j] = dp[i-1][j];
            } else {
                int tmpl = 0;
                int tmpr = 0;
                if (PA[i-1].first > i-1 && PA[i-1].first <= j) tmpl = PA[i-1].second;
                if (PA[j+1].first < j+1 && PA[j+1].first >= i) tmpr = PA[j+1].second;
                dp[i][j] = max(dp[i-1][j] + tmpl, dp[i][j+1] + tmpr);
            }
        }
    }
    int ans = 0;
    rep (i, N) {
        rep (j, N) {
            ans = max(ans, dp[i][j]);
        }
    }

    // output
    cout << ans << endl;
}