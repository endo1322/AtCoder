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

void dfs(vector<vector<int>>& AB, int v, set<int>& seen) {
    seen.insert(v);
    rep (i, AB[v].size()) {
        if (seen.count(AB[v][i]) == 0) {
            dfs(AB, AB[v][i], seen);
        }
    }
}

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<vector<int>> AB(N+1);
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        AB[a].push_back(b);
        AB[b].push_back(a);
    }

    // solve
    set<int> seen;
    dfs(AB, 1, seen);
    string ans = "The graph is connected.";
    rep3 (i, 1, N+1) {
        if (seen.count(i) == 0) {
            ans = "The graph is not connected.";
            break;
        }
    }

    // output
    cout << ans << endl;
}