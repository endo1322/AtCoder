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
using mint = modint;
template<class T> using V = vector<T>;
template<class T> using P = pair<T, T>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T,V<T>,greater<T>>;
const long long INF = 1e18;
const long long MIN_INF = -1e18;

map<char,pair<int, int>> MD4 = {{'L', {-1, 0}}, {'U', {0, -1}}, {'R', {1, 0}}, {'D', {0, 1}}};
vector<int> D4 = {'R', 'D', 'L', 'U'};
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
    int N; cin >> N;

    // solve
    vector<vector<int>> ans(N, vector<int>(N, '-1'));
    int i = 0;
    int j = 0;
    int cnt = 1;
    mint::set_mod(4);
    mint d_mod = 0;
    int r_max = N;
    int d_max = N;
    int l_max = 0;
    int u_max = 1;
    while (cnt < N * N) {
        ans[i][j] = cnt;
        if (D4[d_mod.val()] == 'R') {
            if (j + 1 < r_max) {
                j++;
            } else {
                d_mod++;
                i++;
                r_max--;
            }
        } else if (D4[d_mod.val()] == 'D') {
            if (i + 1 < d_max) {
                i++;
            } else {
                d_mod++;
                j--;
                d_max--;
            }
        } else if (D4[d_mod.val()] == 'L') {
            if (j - 1 >= l_max) {
                j--;
            } else {
                d_mod++;
                i--;
                l_max++;
            }
        } else if (D4[d_mod.val()] == 'U') {
            if (i - 1 >= u_max) {
                i--;
            } else {
                d_mod++;
                j++;
                u_max++;
            }
        }
        cnt++;
    }

    // output
    rep (i, N) {
        rep (j, N) {
            if (i == N / 2 && j == N / 2) {
                cout << 'T' << " ";
                continue;
            }
            cout << ans[i][j];
            if (j != N - 1) cout << " ";
        }
        cout << endl;
    }
}