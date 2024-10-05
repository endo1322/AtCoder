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

double culc_time(pair<int, int>& a, pair<int, int>& b, double v) {
    double dist = sqrt(powl((a.first - b.first), 2)+ powl((a.second - b.second), 2));
    return dist / v;
}

signed main() {
    // input
    int N, S, T; cin >> N >> S >> T;
    vector<vector<pair<int, int>>> A(N);
    rep (i, N) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        A[i].push_back({a, b});
        A[i].push_back({c, d});
    }

    // solve
    double ans = INF;
    vector<int> IDX(N);
    rep (i, N) IDX[i] = i;

    do {
        for (int bit = 0; bit < (1 << N); bit++) {
            pair<int, int> prev = {0, 0};
            double tmp = 0;
            rep (i, N) {
                int idx = IDX[i];
                pair<int, int> next;
                pair<int, int> goal;
                if (bit & (1 << i)) {
                    next = A[idx][0];
                    goal = A[idx][1];
                } else {
                    next = A[idx][1];
                    goal = A[idx][0];
                }
                if (prev == next) {
                    tmp += culc_time(prev, goal, T);
                } else {
                    tmp += culc_time(prev, next, S) + culc_time(next, goal, T);
                }
                prev = goal;
            }
            ans = min(ans, tmp);
        }
    } while (next_permutation(all(IDX)));

    // output
    cout << fixed << setprecision(20) << ans << endl;
}