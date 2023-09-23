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
    int64_t N, M, P; cin >> N >> M >> P;
    vector<int64_t> A(N), B(M);
    rep (i, N) {
        cin >> A.at(i);
    }
    rep (i, M) {
        cin >> B.at(i);
    }

    sort(all(A));
    sort(all(B));
    ll sum = 0;
    vector<ll> SUM(M);
    rep (i, M) {
        sum += B.at(i);
        SUM.at(i) = sum;
    }

    ll ans = 0;
    ll tmp;
    rep (i, N) {
        auto lower = lower_bound(all(B), P-A.at(i));
        int pos = distance(B.begin(), lower);
        if (pos > 0) {
            ans += ((A.at(i) * pos + SUM.at(pos-1)) + (P * (M - pos)));
        } else {
            ans += P * M;
        }
    }
    
    // output
    cout << ans << endl;
}