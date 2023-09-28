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
    vector<pair<int, set<int>>> A(N);
    rep (i, N) {
        int C;
        cin >> C;
        A[i].first = C;
        rep (j, C) {
            int a;
            cin >> a;
            A[i].second.insert(a);
        }
    }
    int X; cin >> X;

    // solve
    vector<pair<int, int>> tmp;
    rep (i, N) {
        if (A[i].second.count(X) != 0) {
            tmp.push_back(make_pair(A[i].first, i));
        }
    }

    sort(all(tmp));

    // output
    vector<int> ans;
    if (tmp.size() > 0) {
        rep (i, N) {
            if (tmp[i].first == tmp[0].first) {
                ans.push_back(tmp[i].second+1);
            } else {
                break;
            }
        }
    }

    cout << ans.size() << endl;
    if (ans.size() > 0) {
        rep (i, ans.size()) {
            if (i != ans.size() - 1) {
                cout << ans[i] << ' ';
            } else {
                cout << ans[i] << endl;
            }
        }
    } else {
        cout << endl;
    }
}