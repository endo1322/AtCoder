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
    int N, M; cin >> N >> M;
    map<string, int> adr;
    rep (i, N) {
        string tmp = "";
        rep (j, 6) {
            char c;
            cin >> c;
            if (j < 3) continue;
            tmp += c;
        }
        if (adr.count(tmp) == 0) {
            adr[tmp] = 1;
        } else {
            adr[tmp]++;
        }
    }
    int ans = 0;
    rep (i, M) {
        string matubi;
        cin >> matubi;
        if (adr.count(matubi) != 0 && adr[matubi] > 0) {
            ans += adr[matubi];
            adr[matubi] -= adr[matubi];
        }
    }

    // output
    cout << ans << endl;
}