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

set<int> culc_p(int N) {
    vector<bool> isP(N+1, true);
    set<int> P;
    isP[0] = isP[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!isP[i]) continue;
        for (int j = i * i; j <= N; j += i) isP[j] = false;
    }
    rep3 (i, 2, N+1) if (isP[i]) P.insert(i);
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
    int H, W, K; cin >> H >> W >> K;
    vector<vector<char>> S(H, vector<char>(W));
    rep (i, H) rep (j, W) cin >> S[i][j];

    // solve
    int ans = INF;
    priority_queue<int> pq;
    rep (i, H) {
        int j = 0;
        bool flag = true;
        int ct_rest = 0;
        while (j + K - 1 < W) {
            if (flag) {
                flag = false;
                bool flag_non_batu = true;
                int pos_batu = -1;
                rep (k, K) {
                    if (S[i][j+k] == '.') ct_rest++;
                    else if (S[i][j+k] == 'o') continue;
                    else if (S[i][j+k] == 'x') {
                        ct_rest = 0;
                        flag_non_batu = false;
                        pos_batu = k;
                    }
                }
                if (flag_non_batu) {
                    ans = min(ans, ct_rest);
                    j++;
                } else {
                    ct_rest = 0;
                    j += pos_batu + 1;
                    flag = true;
                }
            } else {
                bool flag_non_batu = true;
                if (S[i][j-1] == '.') ct_rest--;
                if (S[i][j+K-1] == '.') ct_rest++;
                else if (S[i][j+K-1] == 'x') flag_non_batu = false;
                if (flag_non_batu) {
                    ans = min(ans, ct_rest);
                    j++;
                } else {
                    ct_rest = 0;
                    j += K;
                    flag = true;
                }
            }
        }
    }
    rep (j, W) {
        int i = 0;
        bool flag = true;
        int ct_rest = 0;
        while (i + K - 1 < H) {
            if (flag) {
                flag = false;
                bool flag_non_batu = true;
                int pos_batu = -1;
                rep (k, K) {
                    if (S[i+k][j] == '.') ct_rest++;
                    else if (S[i+k][j] == 'o') continue;
                    else if (S[i+k][j] == 'x') {
                        ct_rest = 0;
                        flag_non_batu = false;
                        pos_batu = k;
                    }
                }
                if (flag_non_batu) {
                    ans = min(ans, ct_rest);
                    i++;
                } else {
                    ct_rest = 0;
                    i += pos_batu + 1;
                    flag = true;
                }
            } else {
                bool flag_non_batu = true;
                if (S[i-1][j] == '.') ct_rest--;
                if (S[i+K-1][j] == '.') ct_rest++;
                else if (S[i+K-1][j] == 'x') flag_non_batu = false;
                if (flag_non_batu) {
                    ans = min(ans, ct_rest);
                    i++;
                } else {
                    ct_rest = 0;
                    i += K;
                    flag = true;
                }
            }
        }
    }
    if (ans == INF) ans = -1;

    // output
    cout << ans << endl;
}