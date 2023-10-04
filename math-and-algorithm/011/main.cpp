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
    int N; cin >> N;
    vector<int> P(3001);
    rep3 (i, 2, 3001) {
        P[i] = i;
    }

    // solve
    rep3 (i, 2, 60) {
        rep3 (j, i+1, P.size()) {
            if (P[j] % i == 0) {
                P.erase(P.begin() + j);
            }
        }
    }

    // output
    rep3 (i, 2, P.size()) {
        if (P[i] <= N) {
            if (P[i] == 2) {
                cout << P[i];
            } else {
            cout << ' ' << P[i];
            }
        } else {
            cout << endl;
            break;
        }
    }
}