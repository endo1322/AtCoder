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
    int N, M; cin >> N >> M;
    string S; cin >> S;
    vector<int> idx(N);
    vector<vector<char>> C(M);
    rep (i, N) {
        int c;
        cin >> c;
        if (C[c-1].size() == 0) {
            C[c-1].push_back(S[i]);
        }
        idx[i] = c-1;
        C[c-1].push_back(S[i]);
    }

    // solve
    rep (i, M) {
        C[i][0] = C[i].back();
    }

    string ans;
    vector<int> C_idx(M, 0);
    rep (i, N) {
        ans += C[idx[i]][C_idx[idx[i]]++];
    }

    // output
    cout << ans << endl;
}