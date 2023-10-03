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
    vector<vector<char>> A(H, vector<char>(W));
    rep (i, H) {
        rep (j, W) {
            char a;
            cin >> a;
            A[i][j] = a;
        }
    }
    vector<vector<char>> B(H, vector<char>(W));
    rep (i, H) {
        rep (j, W) {
            char b;
            cin >> b;
            B[i][j] = b;
        }
    }

    // solve
    vector<vector<char>> shifted(H, vector<char>(W));
    vector<vector<char>> prevh(H, vector<char>(W));
    shifted = A;
    prevh = A;
    string ans = "No";
    rep (i, H) {
        rep (j, H) {
            rep (k, W) {
                if (j != H-1) {
                    shifted[j][k] = prevh[j+1][k];
                } else {
                    shifted[j][k] = prevh[0][k];
                }
            }
        }
        rep (j, W) {
            bool flag = true;
            vector<vector<char>> prevw(H, vector<char>(W));
            prevw = shifted;
            rep (k, H) {
                rep (l, W) {
                    if (l != W-1) {
                        shifted[k][l] = prevw[k][l+1];
                    } else {
                        shifted[k][l] = prevw[k][0];
                    }
                }
            }
            rep (k, H) {
                rep (l, W) {
                    if (shifted[k][l] != B[k][l]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) {
                ans = "Yes";
            }
        }
        if (ans == "Yes") break;
        prevh = shifted;
    }

    // output
    cout << ans << endl;
}