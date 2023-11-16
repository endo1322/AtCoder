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

signed main() {
    // input
    int H, W, N; cin >> H >> W >> N;
    V<V<int>> HW(H, V<int>(W, 0));
    rep (i, N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        HW[a][b]++;
        if (c == H && d == W) continue;
        if (c != H) HW[c][b]--;
        if (d != W) HW[a][d]--;
        if (c != H && d != W) HW[c][d]++;
    }

    // solve
    rep (i, H) {
        rep3 (j, 1, W) {
            HW[i][j] += HW[i][j-1];
        }
    }
    rep (i, W) {
        rep3 (j, 1, H) {
            HW[j][i] += HW[j-1][i];
        }
    }

    // output
    rep (i, H) {
        rep (j, W) {
            cout << HW[i][j];
            if (j == W-1) {
                cout << endl;
            } else {
                cout << ' ';
            }
        }
    }
}