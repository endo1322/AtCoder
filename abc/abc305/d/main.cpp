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
    vector<int> A(N, 0);
    vector<int> SUM(N, 0);
    int sum = 0;
    int st = 0;
    rep (i, N) {
        int a;
        cin >> a;
        A[i] = a;
        if (i == 0) continue;
        if (i % 2 == 1) {
            st = a;
            SUM[i] = SUM[i-1];
        } else {
            sum += (a - st);
            SUM[i] = sum;
        }
    }
    int Q; cin >> Q;
    vector<int> ans(Q);
    rep (i, Q) {
        int l, r;
        cin >> l >> r;
        int low = 0;
        int up = N - 1;
        while (!(low + 1 > up)) {
            int mid = (low + up) / 2;

            if (A[mid] < l) {
                low = mid + 1;
            } else {
                up = mid;
            }
        }
        int l_k = up;
        int sum_l;
        if (l_k % 2 == 1) {
            sum_l = SUM[l_k];
        } else {
            sum_l = SUM[l_k] - (A[l_k] - l);
        }
        low = 0;
        up = N - 1;
        while (!(low + 1 > up)) {
            int mid = (low + up) / 2;

            if (A[mid] < r) {
                low = mid + 1;
            } else {
                up = mid;
            }
        }
        int r_k = up;
        int sum_r;
        if (r_k % 2 == 1) {
            sum_r = SUM[r_k];
        } else {
            sum_r = SUM[r_k] - (A[r_k] - r);
        }
        ans[i] = sum_r - sum_l;
    }

    // output
    rep (i, Q) {
        cout << ans[i] << endl;
    }
}