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
    int N, M; cin >> N >> M;
    V<P<int>> AB(M);
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        AB[i] = {a, b};
    }
    int Q; cin >> Q;
    V<bool> AB_now(M, true);
    V<V<int>> query(Q);
    rep (i, Q) {
        int q; cin >> q;
        if (q == 1) {
            int u; cin >> u;
            u--;
            AB_now[u] = false;
            query[i].push_back(1);
            query[i].push_back(u);
        } else {
            int u, v; cin >> u >> v;
            u--;
            v--;
            query[i].push_back(2);
            query[i].push_back(u);
            query[i].push_back(v);
        }
    }
    dsu uf(N);
    rep (i, M) {
        if (AB_now[i]) {
            uf.merge(AB[i].first, AB[i].second);
        }
    }
    V<string> ans;
    rrep (i, Q) {
        int q = query[i][0];
        if (q == 1) {
            int u = query[i][1];
            uf.merge(AB[u].first, AB[u].second);
        } else {
            int u = query[i][1];
            int v = query[i][2];
            string tmp;
            if (uf.same(u, v)) {
                tmp = "Yes";
            } else {
                tmp = "No";
            }
            ans.push_back(tmp);
        }
    }
    rrep (i, ans.size()) {
        cout << ans[i] << endl;
    }
}