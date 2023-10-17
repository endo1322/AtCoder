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

vector<pair<int, int>> D2 = {{1, 0}, {0, 1}};
int H, W;

void dfs(const map<pair<int, int>, int>& A, const pair<int, int>& pos, const pair<int, int>& gl, int& ans, set<int>& gone) {
    if (gone.count(A.at(pos)) != 0) return;
    gone.insert(A.at(pos));
    if (pos == gl) {
        ans++;
    } else {
        for (auto& d: D2) {
            pair<int, int> next_pos = add_pair(pos, d);
            if (A.count(next_pos) != 0) {
                dfs(A, next_pos, gl, ans, gone);
            }
        }
    }
    gone.erase(A.at(pos));
    return;
}

signed main() {
    // input
    cin >> H >> W;
    map<pair<int, int>, int> A;
    rep (i, H) {
        rep (j, W) {
            int a;
            cin >> a;
            pair<int, int> ij = make_pair(j, i);
            A[ij] = a;
        }
    }

    // solve
    int ans = 0;
    set<int> gone;
    pair<int, int> st = make_pair(0, 0);
    pair<int, int> gl = make_pair(W-1, H-1);
    dfs(A, st, gl, ans, gone);

    // output
    cout << ans << endl;
}