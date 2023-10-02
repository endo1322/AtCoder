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
    vector<string> S(N);
    rep (i, N) {
        string s;
        cin >> s;
        S[i] = s;
    }

    // solve
    sort(all(S));
    string ans = "No";
    do {
        bool flag = true;
        rep3 (i, 1, N) {
            int c = 0;
            rep (k, M) {
                if (S[i-1][k] != S[i][k]) {
                    c++;
                }
            }
            if (c > 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = "Yes";
            break;
        }
    } while (next_permutation(all(S)));

    // output
    cout << ans << endl;
    // rep (i, N) {
    //     cout << S[i] << ": ";
    //     rep (j, tmp[S[i]].size()) {
    //         cout << tmp[S[i]][j] << " ";
    //     }
    //     cout << endl;
    // }
}