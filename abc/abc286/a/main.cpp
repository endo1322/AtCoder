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
template<class T> using P = pair<T, T>;
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
    int N, P, Q, R, S; cin >> N >> P >> Q >> R >> S;
    vector<int> A(N);
    vector<int> usiro;
    vector<int> mae;
    vector<int> B(N);
    rep (i, N) {
        int a;
        cin >> a;
        if (i >= P - 1 && i <= Q - 1) {
            usiro.push_back(a);
        } else if (i >= R - 1 && i <= S - 1) {
            mae.push_back(a);
        } else {
            B[i] = a;
        }
    }

    // solve
    int ct = 0;
    rep3 (i, P-1, Q) {
        B[i] = mae[ct];
        ct++;
    }
    ct = 0;
    rep3 (i, R-1, S) {
        B[i] = usiro[ct];
        ct++;
    }

    // output
    rep (i, N) {
        cout << B[i];
        if (i == N -1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}