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
#define ll long long

vector<pair<int, int>> solve(const vector<vector<char>>& S, int N, int M) {
    vector<pair<int, int>> ret;
    rep (i, N) {
        rep (j, M) {
            bool flag = true;
            rep (k, 3) {
                rep (l, 3) {
                    if (i+8 >= N || j+8 >= M) {
                        flag = false;
                        break;
                    }
                    if (S.at(i+k).at(j+l) != '#' || S.at(i+6+k).at(j+6+l) != '#') {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (S.at(i+3).at(j+k) != '.' || S.at(i+k).at(j+3) != '.' || S.at(i+5).at(j+5+k) != '.' || S.at(i+5+k).at(j+5) != '.' ) {
                        flag = false;
                        break;
                    }
                } else {
                    break;
                };
            }
            if (flag) {
                if (S.at(i+3).at(j+3) == '.' && S.at(i+5).at(j+5) == '.' ) {
                    pair<int, int> tmp = {i, j};
                    ret.push_back(tmp);
                }
            }
        }
    }
    return ret;
}

int main() {
    // input
    int N, M; cin >> N >> M;
    vector<vector<char>> S(N, vector<char>(M));
    rep (i, N) {
        rep (j, M) {
            cin >> S.at(i).at(j);
        }
    }

    // solve
    auto ans = solve(S, N, M);

    // output
    if (ans.size() != 0) {
        rep(i, ans.size()) {
           cout << ans.at(i).first+1 << ' ' << ans.at(i).second+1 << endl;
        }
    } else {
        cout << endl;
    }
}