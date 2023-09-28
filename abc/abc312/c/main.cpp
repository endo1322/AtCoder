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
    int low, up;
    vector<int> A(N);
    rep (i, N) {
        int a;
        cin >> a;
        low = min(low, a);
        up = max(up, a);
        A[i] = a;
    }
    vector<int> B(M);
    rep (i, M) {
        int b;
        cin >> b;
        low = min(low, b);
        up = max(up, b);
        B[i] = b;
    }

    // solve
    sort(all(A));
    sort(rall(B));

    while (!(low + 1 > up)) {
        int mid = (low + up) / 2;

        int na = 0;
        int nb = 0;
        rep (i, N) {
            if (mid >= A[i]) na++; else break;
        }
        rep (i, M) {
            if (mid <= B[i]) nb++; else break;
        }

        if (na >= nb) {
            up = mid;
        } else {
            low = mid + 1;
        }

    }

    // output
    cout << up << endl;
}