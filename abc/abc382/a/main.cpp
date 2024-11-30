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
const long long INF = LLONG_MAX;
const long long MIN_INF = LLONG_MIN;

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

int binary_search(int key, vector<int> &a) {
    int ng = -1;
    int ok = (int)a.size();

    auto isOK = [&](int index) -> bool {
        return a[index] >= key;
    };

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
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
    int N, D; cin >> N >> D;
    string S; cin >> S;

    // solve
    int ans = 0;
    int ct = 0;
    for (auto s: S) {
        if (s == '.') ans++;
        else ct++;
    }
    if (ct == D) {
        ans += ct;
    } else if (ct > D) {
        ans += D;
    }

    // output
    cout << ans << endl;
}