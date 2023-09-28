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
    int H, W; cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    rep (i, H) {
        rep (j, W) {
            cin >> S[i][j];
        }
    }

    // solve
    int mn_x = 500;
    int mx_x = 0;
    int mn_y = 500;
    int mx_y = 0;
    rep (i, H) {
        rep (j, W) {
            if (S[i][j] == '#') {
                mn_x = min(mn_x, j);
                mx_x = max(mx_x, j);
                mn_y = min(mn_y, i);
                mx_y = max(mx_y, i);
            }
        }
    }
    pair<int, int> ans;
    rep3 (i, mn_y, mx_y+1) {
        rep3 (j, mn_x, mx_x+1) {
            if (i < H && j < W) {
                if (S[i][j] == '.') {
                    ans = make_pair(i+1, j+1);
                    break;
                }
            }
        }
    }

    // output
    cout << ans.first << ' ' << ans.second << endl;
}