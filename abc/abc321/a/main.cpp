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
    string N; cin >> N;

    int start = N[0] - '0';
    bool flag = true;
    rep3(i, 1, size(N)) {
        if (start > (N[i] - '0')) {
            start = N[i] - '0';
        } else {
            flag = false;
            break;
        }
    }
    string ans = "No";
    if (flag) {
        ans = "Yes";
    }

    // output
    cout << ans << endl;
}