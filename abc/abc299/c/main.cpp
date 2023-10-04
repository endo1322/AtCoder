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
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<int> culc_p(int N) {
    vector<bool> isP(N, true);
    vector<int> P;
    isP[0] = isP[1] = false;
    rep3 (i, 2, N) {
        if (!isP[i]) continue;
        P.push_back(i);
        for (int j = 1; i * j < N; j++) {
            isP[i*j] = false;
        }
    }
    return P;
}

signed main() {
    // input
    int N; cin >> N;
    string S; cin >> S;

    // solve
    bool flag_mae = false;
    bool flag_ato = false;
    int mx = -1;
    int ct = 0;
    int tmp = 0;
    rep (i, N) {
        char c = S[i];
        if (!flag_mae && !flag_ato && c == 'o' && i > 0 && S[i-1] == '-') {
            flag_mae = true;
            ct++;
            mx = max(mx, ct);
        } else if (flag_mae && c == 'o') {
            ct++;
            mx = max(mx, ct);
        } else if (flag_mae && c == '-') {
            flag_mae = false;
            ct = 0;
        } else if (!flag_mae && !flag_ato && c == 'o') {
            flag_ato = true;
            tmp++;
        } else if (flag_ato && c == 'o') {
            tmp++;
        } else if (flag_ato && c == '-') {
            mx = max(mx, tmp);
            tmp = 0;
            flag_ato = false;
        }
    }

    // output
    cout << mx << endl;
}