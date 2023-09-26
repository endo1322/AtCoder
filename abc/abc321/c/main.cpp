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

int solve(int K) {
    vector<int> ans;
    for (int bit = 2; bit < (1 << 10); bit++) {
        int x = 0;
        for (int i = 9; i >= 0; i--) {
            if (bit & (1 << i)) {
                x *= 10;
                x += i;
            }
        }
        ans.push_back(x);
    }
    sort(all(ans));
    return ans[K-1];
}

signed main() {
    // input
    int K; cin >> K;

    // solve
    auto ans = solve(K);

    // output
    cout << ans << endl;
}