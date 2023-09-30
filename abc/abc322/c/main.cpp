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

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<int> A(N);
    int prev = 0;
    rep (i, M) {
        int a;
        cin >> a;
        int n = a - prev;
        if (n == 0) {
            A[a-1] = 0;
        } else {
            rep3 (j, 1, n+1) {
                A[a-(n-j)-1] = n - j;
            }
        }
        prev = a;
    }

    // output
    rep (i, N) {
        cout << A[i] << endl;
    }
}