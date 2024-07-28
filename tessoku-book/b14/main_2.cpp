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
    int N, K; cin >> N >> K;
    int mid = N / 2;
    vector<int> AA(N);
    rep (i, mid) {
        int a;
        cin >> a;
        AA[i] = a;
    }
    vector<int> AB(N);
    rep (i, N) {
        int a;
        cin >> a;
        AB[i] = a;
    }
   
    // solve
    string ans = "No";
    set<int> SA;
    set<int> SB;
    for (int bit = 0; bit < (1<<mid); bit++) {
        int tmp = 0;
        for (int i = 0; i < mid; i++) {
            if (bit & (1<<i)) {
                tmp += AA[i];
            }
        }
        SA.insert(tmp);
    }
    for (int bit = 0; bit < (1<<N-mid); bit++) {
        int tmp = 0;
        for (int i = 0; i < N-mid; i++) {
            if (bit & (1<<i)) {
                tmp += AB[i];
            }
        }
        SB.insert(tmp);
    }

    for (auto it = SA.begin(); it != SA.end(); ++it) {
        if (SB.count(K - *it)) {
            ans = "Yes";
            break;
        }
    }

    // output
    cout << ans << endl;
}