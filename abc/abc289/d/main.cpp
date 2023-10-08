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
    rep (i, N) {
        int a;
        cin >> a;
        A[i] = a;
    }
    int M; cin >> M;
    vector<int> B(M);
    rep (i, M) {
        int a;
        cin >> a;
        B[i] = a;
    }
    int X; cin >> X;

    // solve
    vector<bool> available(X+1, true);
    rep (i, M) {
        available[B[i]] = false;
    }
    vector<bool> dp(X+1, false);
    dp[0] = true;
    rep3 (i, 1, X+1) {
        if (!available[i]) {
            dp[i] = false;
        } else {
            rep (j, N) {
                if (i - A[j] < 0) continue;
                if (dp[i - A[j]]) dp[i] = true;
            }
        }
    }
    string ans = "No";
    if (dp[X]) ans = "Yes";

    // output
    cout << ans << endl;
}