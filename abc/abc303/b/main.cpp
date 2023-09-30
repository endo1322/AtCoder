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
    vector<set<int>> se(N);
    rep (i, M) {
        vector<int> A(N);
        rep (j, N) {
            int a;
            cin >> a;
            A[j] = a - 1;
            if (j > 0) {
                se[A[j-1]].insert(A[j]);
                se[A[j]].insert(A[j-1]);
            }
        }
    }

    // solve
    int ans = 0;
    rep (i, N) {
        rep (j, N) {
            if (i != j) {
                if (se[i].count(j) == 0) {
                    ans++;
                }
            }
        }
    }
    ans /= 2;

    // output
    cout << ans << endl;
}