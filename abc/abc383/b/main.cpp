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
    int H, W, D; cin >> H >> W >> D;
    vector<vector<char>> S(H, vector<char>(W));
    vector<pair<int, int>> K;
    rep (i, H) rep (j, W) {
        char s;
        cin >> s;
        if (s == '.') K.push_back({i, j});
        S[i][j] = s;
    }

    // solve
    int ans = 0;

    rep (i, K.size()) {
        int ii = K[i].first;
        int jj = K[i].second;
        set<pair<int, int>> visited_i;
        rep3 (di, D * -1, D+1) rep3 (dj, D * -1, D+1) {
            if (abs(di) + abs(dj) > D) continue;
            if (ii + di < 0 || ii + di >= H) continue;
            if (jj + dj < 0 || jj + dj >= W) continue;
            if (S[ii + di][jj + dj] == '.') visited_i.insert({ii + di, jj + dj});
        }
        for (int j = i + 1; j < K.size(); ++j) {
            int ii = K[j].first;
            int jj = K[j].second;
            set<pair<int, int>> visited_j;
            rep3 (di, D * -1, D+1) rep3 (dj, D * -1, D+1) {
                if (abs(di) + abs(dj) > D) continue;
                if (ii + di < 0 || ii + di >= H) continue;
                if (jj + dj < 0 || jj + dj >= W) continue;
                if (S[ii + di][jj + dj] == '.') visited_j.insert({ii + di, jj + dj});
            }

            set<pair<int, int>> result;
            set_union(visited_i.begin(), visited_i.end(), visited_j.begin(), visited_j.end(), inserter(result, result.begin()));

            ans = max(ans, (int)result.size());
        }
    }

    // output
    cout << ans << endl;
}