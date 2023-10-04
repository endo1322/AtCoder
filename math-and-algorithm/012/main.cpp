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

bool p_check(int N) {
    if (N <= 1) {
        return false;
    } else {
        int i = 2;
        while (i * i <= N) {
            if (N % i == 0) {
                return false;
            }
            i++;
        }
        return true;
    }
}

signed main() {
    // input
    int N; cin >> N;

    // solve
    string ans = "No";
    if (p_check(N)) ans = "Yes";

    // output
    cout << ans << endl;
}