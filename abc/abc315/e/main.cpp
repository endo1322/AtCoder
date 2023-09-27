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

void solve(int v, vector<vector<int>>& P, vector<bool>& read, vector<int>& ans) {
    if (read[v]) {
        return;
    } else {
        rep (i, P[v].size()) {
            solve(P[v][i], P, read, ans);
        }
        read[v] = true;
        ans.push_back(v+1);
    }
}

signed main() {
    // input
    int N; cin >> N;
    vector<vector<int>> P(N);
    rep (i, N) {
        int C;
        cin >> C;
        rep (j, C) {
            int p;
            cin >> p;
            P[i].push_back(p-1);
        }
    }

    // solve
    vector<bool> read(N);
    vector<int> ans;
    solve(0, P, read, ans);

    // output
    rep (i, ans.size() - 1) {
        cout << ans[i];
        if (i == ans.size() - 2) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}