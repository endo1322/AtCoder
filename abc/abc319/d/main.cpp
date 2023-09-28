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
    int N, M; cin >> N >> M;
    vector<int> L(N);
    int mn = 0;
    int mx = 0;
    rep (i, N) {
        int l;
        cin >> l;
        mn = max(mn, l);
        mx += l + 1;
        L[i] = l;
    }
    mx--;

    int low = mn;
    int up = mx;

    // solve
    while (!(low + 1 > up)) {
        int mid = (low + up) / 2;

        int row = 1;
        int tmp = 0;
        for (auto l: L) {
            tmp += l;
            if (tmp > mid) {
                row++;
                tmp = l + 1;
            } else {
                tmp++;
            }
        }

        if (row > M) {
            low = mid + 1;
        } else {
            up = mid;
        }
    }

    // output
    cout << up << endl;
}