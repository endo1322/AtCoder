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
#define double long double
using mint = modint998244353;
template<class T> using V = vector<T>;
template<class T> using P = pair<T, T>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T,V<T>,greater<T>>;
const long long INF = 1e18;
const long long MIN_INF = -1e18;

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

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

int binaryToDecimal(const string& S) {
    int res = 0;
    for (char c: S) res = res * 2 + (c - '0');
    return res;
}

signed main() {
    // input
    int N; cin >> N;
    vector<vector<vector<int>>> A(N, vector<vector<int>>(N, vector<int>(N)));
    rep (i, N) {
        rep (j, N) {
            rep (k, N) {
                cin >> A[i][j][k];
            }
        }
    }
    vector<vector<vector<int>>> sum(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

    // 累積和配列を計算
    rep3 (i, 1, N + 1) {
        rep3 (j, 1, N + 1) {
            rep3 (k, 1, N + 1) {
                sum[i][j][k] = A[i-1][j-1][k-1]
                                + sum[i-1][j][k] + sum[i][j-1][k] + sum[i][j][k-1]
                                - sum[i-1][j-1][k] - sum[i-1][j][k-1] - sum[i][j-1][k-1]
                                + sum[i-1][j-1][k-1];
            }
        }
    }

    int Q; cin >> Q;
    vector<int> ans(Q);
    rep (i, Q) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        ans[i] = sum[rx][ry][rz]
                - (lx > 0 ? sum[lx-1][ry][rz] : 0)
                - (ly > 0 ? sum[rx][ly-1][rz] : 0)
                - (lz > 0 ? sum[rx][ry][lz-1] : 0)
                + (lx > 0 && ly > 0 ? sum[lx-1][ly-1][rz] : 0)
                + (lx > 0 && lz > 0 ? sum[lx-1][ry][lz-1] : 0)
                + (ly > 0 && lz > 0 ? sum[rx][ly-1][lz-1] : 0)
                - (lx > 0 && ly > 0 && lz > 0 ? sum[lx-1][ly-1][lz-1] : 0);
    }

    // output
    rep (i, Q) {
        cout << ans[i] << endl;
    }
}
