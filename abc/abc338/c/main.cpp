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
    V<int> Q(N);
    V<int> A(N);    
    V<int> B(N);    
    rep (i, N) {
        int a;
        cin >> a;
        Q[i] = a;
    }
    int amn = INF;
    rep (i, N) {
        int a;
        cin >> a;
        A[i] = a;
        if (A[i] != 0) amn = min(amn, Q[i]/A[i]);
    }
    rep (i, N) {
        int a;
        cin >> a;
        B[i] = a;
    }

    // solve
    int ans = amn;
    // cout << amn << endl;
    rrep (i, amn+1) {
        int bmn = INF;
        bool flag = true;
        rep (j, N) {
            int tmp = Q[j];
            tmp -= A[j] * i;
            if (tmp < B[j]) {
                flag = false;
                break;
            }
            if (B[j] != 0) bmn = min(bmn, tmp / B[j]);
        }
        if (flag) {
            ans = max(ans, i + bmn);
        }
    }

    // output
    cout << ans << endl;
}