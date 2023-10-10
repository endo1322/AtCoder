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
    string S; cin >> S;
    string T; cin >> T;

    // solve
    vector<bool> tmp1(T.size()+1);
    vector<bool> tmp2(T.size()+1);
    bool flag1 = true;
    bool flag2 = true;
    tmp1[0] = true;
    tmp2[T.size()] = true;
    rep (i, T.size()) {
        // cout << S[i] << ' ' << T[i] << endl;
        // cout << S[S.size()-i-1] << T[T.size()-i-1] << endl;
        if (flag1) {
            if (S[i] == T[i] || S[i] == '?' || T[i] == '?') {
                tmp1[i+1] = true;
            } else {
                tmp1[i+1] = false;
                flag1 = false;
            }
        } else {
            tmp1[i] = false;
        }
        if (flag2) {
            if (S[S.size()-i-1] == T[T.size()-i-1] || S[S.size()-i-1] == '?' || T[T.size()-i-1] == '?') {
                tmp2[T.size()-i-1] = true;
            } else {
                tmp2[T.size()-i-1] = false;
                flag2 = false;
            }
        } else {
            tmp2[T.size()-i-1] = false;
        }
        // cout << T.size()-i-1 << endl;
    }
    rep (i, T.size()+1) {
        if (tmp1[i] && tmp2[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}