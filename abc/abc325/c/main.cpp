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
    int H, W; cin >> H >> W;
    map<pair<int, int>, char> S;
    rep (i, H) {
        rep (j, W) {
            char c;
            cin >> c;
            auto pos = make_pair(j, i);
            S[pos] = c;
        }
    }

    // solve
    int ans = 0;
    set<pair<int, int>> seen;
    rep (i, H) {
        rep (j, W) {
            P<int> ji = {j, i};
            if (S[ji] == '.' || seen.count(ji) != 0) continue;
            queue<P<int>> tmp;
            tmp.push(ji);
            while (!tmp.empty()) {
                auto pos = tmp.front();
                tmp.pop();

                for (auto& d: D8) {
                    auto n_pos = add_pair(pos, d);
                    if (S.count(n_pos) != 0 && S[n_pos] == '#' && seen.count(n_pos) == 0) {
                        tmp.push(n_pos);
                        seen.insert(n_pos);
                    }
                }
            }
            ans ++;
        }
    }
    // output
    cout << ans << endl;
}