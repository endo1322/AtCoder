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

void dfs(vector<vector<int>>& A, int idx, int seki, int& ans, int N, int X) {
    if (idx == N) {
        if (seki == X) ans++;
    } else {
        for (auto a: A[idx]) {
            if (X < a * seki) continue;
            dfs(A, idx+1, a*seki, ans, N, X);
        }
    }
}

signed main() {
    // input
    int N, X; cin >> N >> X;
    vector<vector<int>> A(N);
    rep (i, N) {
        int L; cin >> L;
        rep (j, L) {
            int a; cin >> a;
            A[i].push_back(a);
        }
    }

    // solve
    int ans = 0;
    dfs(A, 0, 1, ans, N, X);

    // output
    cout << ans << endl;
}