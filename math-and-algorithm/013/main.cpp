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

void d_check(vector<int>& ans, int N) {
    int i = 1;
    while (i * i <= N) {
        if (N % i == 0) {
            if (i == N/i) {
                ans.push_back(i);
            } else {
                ans.push_back(i);
                ans.push_back(N/i);
            }
        }
        i++;
    }
}

signed main() {
    // input
    int N; cin >> N;

    // solve
    vector<int> ans;
    d_check(ans, N);

    // output
    rep (i, ans.size()) {
        cout << ans[i] << endl;
    }
}