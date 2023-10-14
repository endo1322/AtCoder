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
    vector<vector<int>> A(N, vector<int>(N));
    rep (i, N) {
        rep (j, N) {
            int a;
            cin >> a;
            A[i][j] = a;
        }
    }
    vector<vector<int>> B(N, vector<int>(N));
    rep (i, N) {
        rep (j, N) {
            int a;
            cin >> a;
            B[i][j] = a;
        }
    }

    // solve
    string ans = "No";
    rep (i, 4) {
        bool flag = true;
        rep (j, N) {
            rep (k, N) {
                if (A[j][k] == 1 && B[j][k] != 1) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) {
            ans = "Yes";
            break;
        } else {
            vector<vector<int>> AA(N, vector<int>(N));
            rep (j, N) {
                rep (k, N) {
                    AA[j][k] = A[N-1-k][j];
                }
            }
            A = AA;
        }
    }

    // output
    cout << ans << endl;
}