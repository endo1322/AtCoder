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
    int N, M; cin >> N >> M;
    vector<int> A(N);
    rep (i, N) {
        A[i] = 50;
    }
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        A[b-1] = A[a-1] - 1;
    }

    // solve
    int ans = 0;
    bool flag = false;
    rep (i, N) {
        if (A[i] == 50) {
            if (flag) {
                ans = -1; 
                break;
            }
            ans = i+1;
            flag = true;
        }
    }

    // output
    cout << ans << endl;
}