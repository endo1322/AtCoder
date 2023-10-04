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

signed main() {
    // input
    int N, T; cin >> N >> T;
    int t_max = 0;
    int one_max = 0;
    int t_idx, one_idx;
    vector<int> C(N);
    rep (i, N) {
        int a;
        cin >> a;
        C[i] = a;
    }
    rep (i, N) {
        int a;
        cin >> a;
        if (i == 0) {
            one_max = a;
            one_idx = i+1;
        } 
        if (C[i] == T) {
            if (t_max < a) {
                t_max = a;
                t_idx = i+1;
            }
            t_max = max(t_max, a);
        } else if (C[i] == C[0]) {
            if (one_max < a) {
                one_max = a;
                one_idx = i+1;
            }
        }
    }

    // solve
    int ans;
    if (t_max == 0) {
        ans = one_idx;
    } else {
        ans = t_idx;
    }

    // output
    cout << ans << endl;
}