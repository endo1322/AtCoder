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

int sum = 0;
int ans = 0;
set<int> se;

void dfs(vector<vector<pair<int, int>>>& ABC, int v, int dist) {
    se.insert(v);
    sum += dist;
    ans = max(ans, sum);
    rep (i, ABC[v].size()) {
        int nv = ABC[v][i].first;
        int nc = ABC[v][i].second;
        if (se.count(nv) == 0) {
            dfs(ABC, nv, nc);
        }
    }
    sum -= dist;
    se.erase(v);
}

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> ABC(N);
    rep (i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        ABC[a-1].push_back(make_pair(b-1, c));
        ABC[b-1].push_back(make_pair(a-1, c));
    }

    // solve
    rep (i, N) {
        dfs(ABC, i, 0);
    }

    // output
    cout << ans << endl;
}