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
    vector<int> A = {3, 1, 4, 1, 5, 9};
    char p, q; cin >> p >> q;

    // solve
    int ip = p - 'A';
    int iq = q - 'A';
    int mn = min(ip, iq);
    int diff = abs(ip - iq);
    int ans = 0;
    rep3 (i, mn, mn + diff) {
        ans += A[i];
    }

    // output
    cout << ans << endl;
}