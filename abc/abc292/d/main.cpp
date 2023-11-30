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

void dfs(int n, vector<vector<int>>& AA, int& u_ct, int& v_ct, set<int>& seen) {
    if (seen.count(n) == 0) { 
        u_ct++;
    } else {
        return;
    }
    seen.insert(n);
    vector<vector<int>> dammy = AA;
    for (auto a: dammy[n]) {
        v_ct++;
        AA.erase(AA.begin());
        dfs(a, AA, u_ct, v_ct, seen);
    }
    return;
}

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<int> U(M), V(M);
    dsu uf(N);
    rep (i, M) {
        int u, v;
        cin >> u >> v;
        U[i] = --u;
        V[i] = --v;
        uf.merge(u, v);
    }

    // solve
    vector<int> vN(N), eN(N);
    rep (i, N) {
        vN[uf.leader(i)]++;
    }
    rep (i, M) {
        eN[uf.leader(U[i])]++;
    }
    string ans = "Yes";
    rep (i, N) {
        if (vN[i] != eN[i]) {
            ans = "No";
            break;
        }
    }

    // output
    cout << ans << endl;
}