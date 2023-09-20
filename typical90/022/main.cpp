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
    long long A, B, C; cin >> A >> B >> C;
    long long size = gcd(A, gcd(B, C));
    long long ans = A / size + B / size + C / size - 3;

    // output
    cout << ans << endl;
}