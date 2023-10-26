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
    vector<vector<int>> ABC(N, vector<int> (3));
    rep (i, N) {
        int a, b, c;
        cin >> a >> b >> c;
        ABC[i][0] = a;
        ABC[i][1] = b;
        ABC[i][2] = c;
    }

    // solve
    vector<vector<int>> dp(N, vector<int> (3));
    dp[0][0] = ABC[0][0];
    dp[0][1] = ABC[0][1];
    dp[0][2] = ABC[0][2];
    rep3 (i, 1, N) {
        rep (j, 3) {
            int tmp = 0;
            rep (k, 3) {
                if (j == k) continue;
                tmp = max(tmp, dp[i-1][k]+ABC[i][j]);
            }
            dp[i][j] = tmp;
        }
    }
    int ans = 0;
    rep (i, 3) {
        ans = max(ans, dp[N-1][i]);
    }

    // output
    cout << ans << endl;
}