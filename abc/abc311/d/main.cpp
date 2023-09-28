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

vector<pair<int, int>> D = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
set<pair<int, int>> gone;

void dfs(pair<int, int>& xy, vector<vector<char>>& S) {
    if (gone.count(xy) == 0) {
        gone.insert(xy);
        auto x = xy.first;
        auto y = xy.second;
        for (auto [dx, dy]: D) {
            if (S[y+dy][x+dx] != '#') {
                int nx = x + dx;
                int ny = y + dy;
                pair<int, int> nxy = make_pair(nx, ny);

                while (S[ny][nx] == '.') {
                    if (S[ny+dy][nx+dx] == '#') {
                        dfs(nxy, S);
                        break;
                    } else {
                        gone.insert(nxy);
                        nx += dx;
                        ny += dy;
                        nxy = make_pair(nx, ny);
                    }
                }
            }
        }
    }
}

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<vector<char>> S(N, vector<char>(M));
    rep (i, N) {
        rep (j, M) {
            cin >> S[i][j];
        }
    }

    // solve
    pair<int, int> st = {1, 1};
    dfs(st, S);

    // output
    cout << gone.size() << endl;
}