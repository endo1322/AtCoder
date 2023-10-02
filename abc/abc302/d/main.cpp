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
    int N, M, D; cin >> N >> M >> D;
    vector<int> A(N);
    vector<int> B(M);
    rep (i, N) {
        cin >> A.at(i);
    }
    rep (i, M) {
        cin >> B.at(i);
    }

    // solve
    sort(rall(A));
    sort(rall(B));
    int i = 0;
    int j = 0;
    int ans = -1;
    while (true) {
        if (i >= N || j >= M) break;
        if (abs(A[i] - B[j]) > D) {
            if (A[i] > B[j]) {
                i++;
            } else {
                j++;
            }
        } else {
            ans = A[i] + B[j];
            break;
        }
    }

    // output
    cout << ans << endl;
}