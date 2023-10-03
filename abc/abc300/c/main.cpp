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

signed main() {
    // input
    int H, W; cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    rep (i, H) {
        rep (j, W) {
            char c;
            cin >> c;
            C[i][j] = c;
        }
    }

    // solve
    vector<vector<char>> seen(H, vector<char>(W));
    seen = C;
    vector<int> ans(min(H, W), 0);
    rep (i, H) {
        rep (j, W) {
            if (seen[i][j] == '#') {
                int c = 1;
                int diff = 1;
                while (true) {
                    if (seen[i+diff][j+diff] == '#' && seen[i+diff-1][j+diff+1] == '#') {
                        break;
                    } else {
                        c++;
                        diff++;
                    }
                }
                ans[c-1]++;
                int size = 2*c+1;
                rep (k, size) {
                    seen[i+k][j+k] = '.';
                    seen[i+size-k-1][j+k] = '.';
                }
            }
        }
    }
    

    // output
    rep (i, ans.size()) {
        cout << ans[i];
        if (i == ans.size()-1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}