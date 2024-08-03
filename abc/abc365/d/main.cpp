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
using mint = modint998244353;
template<class T> using V = vector<T>;
template<class T> using P = pair<T, T>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T,V<T>,greater<T>>;
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

int binaryToDecimal(const string& S) {
    int res = 0;
    for (char c: S) res = res * 2 + (c - '0');
    return res;
}

signed main() {
    // input
    int N; cin >> N;
    string S; cin >> S;

    // solve
    int ans = 0;
    vector<vector<int>> dp(3, vector<int>(N+1, -1));
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;

    rep3 (i, 1, N + 1) {
        int win, aiko;
        int prev_r = dp[0][i-1];
        int prev_s = dp[1][i-1];
        int prev_p = dp[2][i-1];
        if (S[i-1] == 'R') {
            // R
            dp[0][i] = max(prev_s, prev_p);
            // S
            // dp[1][i] = max(prev_r + 1, prev_p);
            // P
            dp[2][i] = max(prev_r + 1, prev_s + 1);
        } else if (S[i-1] == 'S') {
            // R
            dp[0][i] = max(prev_s + 1, prev_p + 1);
            // S
            dp[1][i] = max(prev_r, prev_p);
            // P
            // dp[2][i] = max(prev_r, prev_s + 1);
        } else {
            // R
            // dp[0][i] = max(prev_s, prev_p + 1);
            // S
            dp[1][i] = max(prev_r + 1, prev_p + 1);
            // P
            dp[2][i] = max(prev_r, prev_s);
        }
    }

    ans = max(dp[0][N], max(dp[1][N], dp[2][N]));

    // output
    cout << ans << endl;
}