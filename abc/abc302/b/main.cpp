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

int H, W;

bool solve(vector<vector<char>> S, vector<char>& snuke, int idx, pair<int, int> pos, int dx, int dy) {
    if (idx == 3) return true;
    int x = pos.first;
    int y = pos.second;
    int xx = x + dx;
    int yy = y + dy;
    if (xx < 0 || xx >= W || yy < 0 || yy >= H) return false;
    if (S[yy][xx] == snuke[idx]) {
        if (solve(S, snuke, idx+1, make_pair(xx, yy), dx, dy)) return true; else return false;
    } else {
        return false;
    }
}

signed main() {
    // input
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));
    stack<pair<int, int>> s_pos;
    vector<char> snuke = {'u', 'k', 'e'};
    vector<pair<int, int>> D = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    rep (i, H) {
        rep (j, W) {
            char c;
            cin >> c;
            if (c == 's') {
                s_pos.push(make_pair(j, i));
            }
            S[i][j] = c;
        }
    }

    // solve
    vector<pair<int, int>> ans(5);
    bool flag = false;
    while (!s_pos.empty()) {
        auto pos = s_pos.top();
        s_pos.pop();

        int x = pos.first;
        int y = pos.second;
        ans[0] = make_pair(x+1, y+1);
        
        for (auto& [dx, dy]: D) {
            if (x + dx < 0 || x + dx >= W || y + dy < 0 || y + dy >= H) continue;
            if (S[y+dy][x+dx] == 'n') {
                if (solve(S, snuke, 0, make_pair(x+dx, y+dy), dx, dy)) {
                    x = x + dx;
                    y = y + dy;
                    rep3 (i, 1, 5) {
                        ans[i] = make_pair(x+1, y+1);
                        x += dx;
                        y += dy;
                    }
                    flag = true;
                    break;
                }
            }
        }
        if (flag) break;
    }

    // output
    rep (i, 5) {
        cout << ans[i].second << ' ' << ans[i].first << endl;
    }
}