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
    int N; cin >> N;
    V<V<int>> AB{1501, V<int>(1501, 0)};
    rep (i, N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a;
        b;
        c;
        d;
        AB[a][b]++;
        AB[c][b]--;
        AB[a][d]--;
        AB[c][d]++;
    }

    // solve
    rep (i, 1501) {
        rep3 (j, 1, 1501) {
            AB[i][j] += AB[i][j-1];
        }
    }
    rep (i, 1501) {
        rep3 (j, 1, 1501) {
            AB[j][i] += AB[j-1][i];
        }
    }
    int ans = 0;
    rep (i, 1501) {
        rep (j, 1501) {
            if (AB[i][j] != 0) ans++;
        }
    }

    // output
    cout << ans << endl;
}