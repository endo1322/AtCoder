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
vector<vector<int>> D = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
set<pair<int, int>> used;

bool dfs(pair<int, int> n, const vector<vector<char>>& C) {
    used.insert(n);
    int x = n.first;
    int y = n.second;
    char c = C[y][x];
    if (c == 'g') {
        return true;
    } else if (c == '#') {
        return false;
    } else {
        for (auto d: D) {
            int dx = d[0];
            int dy = d[1];
            int xx = x + dx;
            int yy = y + dy;
            if (xx < 0 || xx >= W || yy < 0 || yy >= H) continue;
            pair<int, int> xy = make_pair(xx, yy);
            if (used.count(xy) == 0) {
                if (dfs(xy, C)) return true;
            }
        }
    }
    return false;
}

signed main() {
    // input
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    pair<int, int> st, gl;
    rep (i, H) {
        rep (j, W) {
            char c;
            cin >> c;
            if (c == 's') {
                st = make_pair(j, i);
            }
            C[i][j] = c;
        }
    }

    // solve
    used.insert(st);
    bool ans = dfs(st, C);

    // output
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}