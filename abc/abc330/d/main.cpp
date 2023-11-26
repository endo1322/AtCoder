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

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

signed main() {
    // input
    int N; cin >> N;
    V<V<char>> C(N, V<char>(N));
    rep (i, N) {
        rep (j, N) {
            char c;
            cin >> c;
            C[i][j] = c;
        }
    }

    // solve
    map<int, int> tate;
    map<int, int> yoko;
    rep (i, N) {
        int ct_tate = 0;
        int ct_yoko = 0;
        rep (j, N) {
            if (C[i][j] == 'o') ct_yoko++;
            if (C[j][i] == 'o') ct_tate++;
        }
        yoko[i] = ct_yoko;
        tate[i] = ct_tate;
    }

    int ans = 0;
    rep (i, N) {
        int y = yoko[i];
        int tmp = 0;
        rep (j, N) {
            int t = tate[j];
            if (C[i][j] == 'o') {
                tmp += (t - 1) * (y - 1);
            }
        }
        ans += tmp;
    }

    // output
    cout << ans << endl;
}