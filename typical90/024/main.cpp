#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REPR(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define RALL(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

int main() {
    // input
    int N, K; cin >> N >> K;
    vector<int64_t> A(N), B(N);
    REP (i, N) {
        cin >> A.at(i);
    }
    long long diff = 0;
    REP (i, N) {
        cin >> B.at(i);
        diff += abs(A.at(i) - B.at(i));
    }
    string ans;
    if (diff <= K and (diff + K) % 2 == 0) {
        ans = "Yes";
    } else {
        ans = "No";
    }

    // output
    cout << ans << endl;
}