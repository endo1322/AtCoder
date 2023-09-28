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
    vector<int> A(N);
    int sum = 0;
    rep (i, N) {
        int a;
        cin >> a;
        A[i] = a;
        sum += a;
    }

    int ave = sum / N;
    int mod = sum % N;
    vector<int> B(N);
    rep (i, N) {
        if (i < N - mod) {
            B[i] = ave;
        } else {
            B[i] = ave + 1;
        }
    }
    sort(all(A));

    // solve
    int ans = 0;
    rep (i, N) {
        ans += abs(A[i] - B[i]);
    }
    ans /= 2;

    // output
    cout << ans << endl;
}