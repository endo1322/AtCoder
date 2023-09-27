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
    vector<char> snuke = {'s', 'n', 'u', 'k', 'e'};
    vector<vector<int>> D = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    pair<int, int> st = make_pair(0, 0);
    pair<int, int> gl = make_pair(W-1, H-1);
    set<pair<int, int>> used;
    queue<pair<int, pair<int, int>>> q;

    string ans = "No";
    q.push(make_pair(0, st));
    while (!q.empty()) {
        int ct = q.front().first;
        pair<int, int> xy = q.front().second;
        q.pop();

        if (used.count(xy) == 0 && S[xy.second][xy.first] == snuke[ct%5]) {
            used.insert(xy);
            if (xy == gl) {
                ans = "Yes";
                break;
            } else {
                for (auto& d: D) {
                    if (xy.first+d[0] >= 0 && xy.first+d[0] < W && xy.second+d[1] >= 0 && xy.second+d[1] < H) {
                        q.push(make_pair(ct+1, make_pair(xy.first+d[0], xy.second+d[1])));
                    }
                }
            }
        }
    }

    // output
    cout << ans << endl;
}