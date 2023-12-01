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

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int binaryToDecimal(const string& S) {
    int res = 0;
    for (char c: S) res = res * 2 + (c - '0');
    return res;
}

signed main() {
    // input
    string S; cin >> S;
    int N; cin >> N;

    // solve
    while (true) {
        int tmp = 0;
        int tmp_idx;
        bool flag = true;
        rep (i, S.size()) {
            if (flag && S[i] == '?') {
                tmp += powl(2, S.size()-i-1);
                tmp_idx = i;
                flag = false;
            } else if (S[i] == '1') {
                tmp += powl(2, S.size()-i-1);
            }
        }
        if (flag) break;
        if (N >= tmp) {
            S[tmp_idx] = '1';
        } else {
            S[tmp_idx] = '0';
        }
    }
    int ans = binaryToDecimal(S);
    if (ans > N) {
        ans = -1;
    }

    // output
    cout << ans << endl;
}