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
    int L, N1, N2; cin >> L >> N1 >> N2;
    vector<pair<int, int>> L1(N1);
    vector<pair<int, int>> L2(N2);
    rep (i, N1) {
        int v, l;
        cin >> v >> l;
        L1[i] = make_pair(v, l);
    }
    rep (i, N2) {
        int v, l;
        cin >> v >> l;
        L2[i] = make_pair(v, l);
    }

    // solve
    int ans = 0;
    int l1 = 0;
    int l2 = 0;
    int l1idx = 0;
    int l2idx = 0;
    while (true) {
        if (l1idx > N1 - 1 || l2idx > N2 - 1) break;
        if (L1[l1idx].first == L2[l2idx].first) {
            int mn = min(L1[l1idx].second, L2[l2idx].second);
            ans += mn;
            if (L1[l1idx].second - mn == 0) {
                l1idx++;
            } else {
                L1[l1idx].second -= mn;
            }
            if (L2[l2idx].second - mn == 0) {
                l2idx++;
            } else {
                L2[l2idx].second -= mn;
            }
        } else {
            int mn = min(L1[l1idx].second, L2[l2idx].second);
            if (L1[l1idx].second - mn == 0) {
                l1idx++;
            } else {
                L1[l1idx].second -= mn;
            }
            if (L2[l2idx].second - mn == 0) {
                l2idx++;
            } else {
                L2[l2idx].second -= mn;
            }
        }
    }

    // output
    cout << ans << endl;
}