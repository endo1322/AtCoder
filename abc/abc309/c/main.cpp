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
#define ll long long

int main() {
    // input
    int N, K; cin >> N >> K;
    vector<vector<int64_t>> A(N, vector<int64_t>(2));
    rep (i, N) {
        cin >> A.at(i).at(0) >> A.at(i).at(1);
    }
    sort(rall(A));

    ll ans = 1;
    ll sum = 0;
    rep (i, N) {
        ll a, b;
        a = A.at(i).at(0);
        b = A.at(i).at(1);
        sum += b;
        if (sum > K) {
            ans = a + 1;
            break;
        }
    }
    // output
    cout << ans << endl;
}