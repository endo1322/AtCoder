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

signed main() {
    // input
    int N; cin >> N;
    vector<vector<int>> A(N);
    int N3 = N * 3;
    rep (i, N3) {
        int a;
        cin >> a;
        A[a-1].push_back(i);
    }

    // solve
    vector<pair<int, int>> ans(N); 
    rep (i, N) {
        ans[i].first = A[i][1];
        ans[i].second = i;
    }
    sort(all(ans));

    // output
    rep (i, N) {
        cout << ans[i].second + 1;
        if (i == N - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}