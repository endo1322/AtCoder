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
    int M; cin >> M;
    vector<int> D(M);
    int sum = 0;
    rep (i, M) {
        int d;
        cin >> d;
        sum += d;
        D[i] = d;
    }

    int md = (sum+1) / 2;

    // solve
    int ans_m, ans_d;
    int tmp = md;
    rep (i, M) {
        tmp -= D[i];
        if (tmp <= 0) {
            ans_m = i + 1;
            tmp += D[i];
            break;
        }
    }
    ans_d = tmp;

    // output
    cout << ans_m << ' ' << ans_d << endl;
}