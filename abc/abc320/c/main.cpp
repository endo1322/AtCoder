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

int main() {
    // input
    int M; cin >> M;
    vector<string> S(3);
    rep (i, 3) {
        cin >> S.at(i);
    }

    // solve
    int min = 1000;
    rep(i, S.at(0).size()) {
        rep(j, S.at(1).size()) {
            if (S.at(0).at(i) != S.at(1).at(j)) {
                continue;
            } else {
                rep(k, S.at(2).size()) {
                    if (S.at(1).at(j) != S.at(2).at(k)) {
                       continue;
                    } else {
                        int tmp;
                        if (i == j && i == k) {
                            tmp = ((i % M) + 2 * M);
                        } else if (i == j || j == k || i == k) {
                            tmp = ((i % M) + M);
                        } else {
                            int mx = max(i, max(j, k));
                            tmp = mx % M;
                        }
                        if (tmp < min) {
                            min = tmp;
                        }
                    }
                }
            }
        }
    }
    if (min == 1000) {
        min = -1;
    }

    // output
    cout << min << endl;
}