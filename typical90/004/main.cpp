#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REPR(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)

vector<vector<int64_t>> solve(int h, int w, const vector<vector <int64_t>>& a) {
    vector<vector<int64_t>> B(h, vector<int64_t>(w));
    vector<vector<int>> tmp_v(2);
    int tmp;
    REP (i, h) {
        tmp = 0;
        REP (j, w) {
            tmp += a.at(i).at(j);
        }
        tmp_v.at(0).push_back(tmp);
    }
    REP (i, w) {
        tmp = 0;
        REP (j, h) {
            tmp += a.at(j).at(i);
        }
        tmp_v.at(1).push_back(tmp);
    }
    REP (i, h) {
        REP (j, w) {
            B.at(i).at(j) = tmp_v.at(0).at(i) + tmp_v.at(1).at(j) - a.at(i).at(j);
        }
    }

    return B;
}

int main() {
    // input
    int H, W; cin >> H >> W;
    vector<vector<int64_t>> A(H, vector<int64_t>(W));
    REP (i, H) {
        REP (j, W) {
            cin >> A.at(i).at(j);
        }
    }

    // solve
    auto ans = solve(H, W, A);

    // output
    REP (i, H) {
        REP (j, W) {
            cout << ans.at(i).at(j);
            if (!(j == W-1)) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}