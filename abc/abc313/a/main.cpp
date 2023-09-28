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
    vector<int> P(N);
    int mx = 0;
    int iti;
    bool flag = false;
    rep (i, N) {
        int p;
        cin >> p;
        if (i == 0) iti = p; else if (iti == p) flag = true;
        mx = max(mx, p);
    }

    // solve
    int ans;
    if (mx == iti && flag) ans = 1; else if (mx == iti) ans = 0; else ans = mx - iti + 1;

    // output
    cout << ans << endl;
}