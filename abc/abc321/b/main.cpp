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
#define ll long long

int main() {
    // input
    int N, X; cin >> N >> X;
    vector<int64_t> A(N-1);
    int min = 101;
    int min_i;
    int max = 0;
    int max_i;
    rep (i, N-1) {
        cin >> A.at(i);
        if (A.at(i) > max) {
            max = A.at(i);
            max_i = i;
        }
        if (A.at(i) < min) {
            min = A.at(i);
            min_i = i;
        }
    }

    ll sum = 0;
    rep(i, N-1) {
        if (i != min_i && i != max_i) {
            sum += A.at(i);
        }
    }
    if (min_i == max_i) {
        sum -= A.at(min_i);
    }

    int ans;
    if (sum >= X) {
        ans = 0;
    } else if (sum < X && X - sum > max) {
        ans = -1;
    } else if (sum < X && X - sum <= min){
        ans = 0;
    } else {
        ans = X - sum;
    }

    // output
    cout << ans << endl;
}