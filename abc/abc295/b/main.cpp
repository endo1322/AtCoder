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
template<class T> using P = pair<T, T>;
const long long INF = 1e18;
const long long MIN_INF = -1e18;

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

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

signed main() {
    // input
    int R, C; cin >> R >> C;
    map<P<int>, int> bomb;
    vector<vector<char>> board(R, vector<char>(C));
    // map<P<int>, char> board;

    rep (i, R) {
        rep (j, C) {
            char c;
            cin >> c;
            if (c != '.' && c != '#') {
                int tmp = c - '0';
                bomb[{i, j}] = tmp;
                board[i][j] = '#';
            } else {
                bomb[{i, j}] = 0;
                board[i][j] = c;
            }
        }
    }

    // solve
    map<P<int>, int> result;
    rep (i, R) {
        rep (j, C) {
            if (bomb[{i,j}] != 0) {
                int tmp = bomb[{i,j}] + 1;
                queue<P<int>> que;
                que.push({i,j});
                rep (k, tmp) {
                    int qsize = que.size();
                    rep (l, qsize) {
                        auto pos = que.front();
                        que.pop();
                        if (bomb.count(pos) == 0) continue;
                        result[pos] = true;
                        for (auto d: D4) {
                            que.push(add_pair(pos, d));
                        }
                    }
                }
            } else {
                if (!result[{i,j}]) result[{i,j}] = false;
            }
        }
    }

    vector<vector<char>> ans(R, vector<char>(C));
    rep (i, R) {
        rep (j, C) {
            if ((result[{i,j}] && board[i][j] == '#') || board[i][j] == '.') {
                ans[i][j] = '.';
            } else {
                ans[i][j] = '#';
            }
        }
    }

    // output
    rep (i, R) {
        rep (j, C) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}