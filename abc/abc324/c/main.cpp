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
    string T; cin >> T;
    vector<string> S(N);
    rep (i, N) {
        string s;
        cin >> s;
        S[i] = s;
    }

    // solve
    vector<int> ans;
    rep (i, N) {
        int mae = 0;
        int ato = 0;
        bool flag_mae = true;
        bool flag_ato = true;
        rep (j, T.size()) {
            if (flag_mae && T[j] == S[i][j]) {
                mae++;
            } else if (flag_mae && T[j] != S[i][j]) {
                flag_mae = false;
            }
            if (flag_ato && T[T.size()-j-1] == S[i][S[i].size()-j-1]) {
                ato++;
            } else if (flag_ato && T[T.size()-j-1] != S[i][S[i].size()-j-1]) {
                flag_ato = false;
            }
            if (!flag_ato && !flag_mae) {
                break;
            }
        }
        if ((mae == T.size() && ato == T.size() && T.size() == S[i].size()) ||      // 一致
            (mae + ato >= T.size() && T.size() == S[i].size()-1) ||                 // 挿入
            (mae + ato >= T.size()-1 && T.size() == S[i].size()+1) ||               // 削除
            (mae + ato == T.size()-1 && T.size() == S[i].size())) {                 // 置換
            ans.push_back(i+1);
        }
    }

    // output
    cout << ans.size() << endl;
    if (ans.size()) {
        rep (i, ans.size()) {
            cout << ans[i];
            if (i == ans.size() - 1) {
                cout << endl;
            } else {
                cout << ' ';
            }
        }
    } else {
        cout << endl;
    }
}