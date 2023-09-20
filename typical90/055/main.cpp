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

bool solve(const vector<int64_t>& A, const vector<int64_t>& index, int64_t p, int64_t q) {
    ll sum_mod = 1;
    for (auto idx: index) {
        sum_mod *= A.at(idx) % p;
        sum_mod %= p;
    }
    if (sum_mod % p == q) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // input
    int64_t N, P, Q; cin >> N >> P >> Q;
    vector<int64_t> A(N);
    rep (i, N) {
        cin >> A.at(i);
    }

    // solve
    int64_t count = 0;
    vector<int64_t> tmp(5);
    rrep (i, N) {
        rrep (j, i) {
            rrep(k, j) {
                rrep(l, k) {
                    rrep(n, l) {
                        tmp = {i, j, k, l, n};
                        if (solve(A, tmp, P, Q)) count++;
                    }
                }
            }
        }
    }
    auto ans = count;

    // output
    cout << ans << endl;
}