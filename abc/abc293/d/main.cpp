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

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<vector<int>> A(N);
    vector<int> deg(N, 0);
    rep (i, M) {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;
        A[a].push_back(c);
        A[c].push_back(a);
        deg[a]++;
        deg[c]++;
    }

    // solve
    set<int> seen;
    pair<int, int> ans = {0, 0};
    rep (i, N) {
        if (seen.count(i) == 0) {
            queue<int> que;
            bool flag = true;
            que.push(i);
            while (!que.empty()) {
                int x = que.front();
                que.pop();
                if (deg[x] != 2) flag = false;
                seen.insert(x);
                rep (i, A[x].size()) {
                    if (seen.count(A[x][i]) == 0) que.push(A[x][i]);
                }
            }
            if (flag) ans.first++; else ans.second++;
        }
    }

    // output
    cout << ans.first << ' ' << ans.second << endl;
}