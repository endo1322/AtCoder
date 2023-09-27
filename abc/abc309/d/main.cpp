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

int solve(int N, const vector<vector<int>>& A, vector<int>& D, set<int>& seen) {
    int mx = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

        int v_num = v.first;
        int v_dist = v.second;
        if (seen.count(v_num) == 0) {
            seen.insert(v_num);
            mx = max(mx, v_dist);
            rep (i, A[v_num].size()) {
                q.push(make_pair(A[v_num][i], v_dist+1));
            }
        }
    }
    return mx;
}

signed main() {
    // input
    int N1, N2, M; cin >> N1 >> N2 >> M;
    vector<vector<int>> A(N1+N2);
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        A[a-1].push_back(b-1);
        A[b-1].push_back(a-1);
    }

    // solve
    vector<int> dist(N1+N2);
    set<int> seen;
    auto ans1 = solve(0, A, dist, seen);
    auto ans2 = solve(N1+N2-1, A, dist, seen);
    int ans = ans1 + ans2 + 1;

    // output
    cout << ans << endl;
}