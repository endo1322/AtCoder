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
    map<int, int> A;
    int same_max = 0;
    rep (i, N) {
        int f, s;
        cin >> f >> s;
        if (A.count(f) == 0) {
            A[f] = s;
        } else {
            int ss = A[f];
            int mx = max(ss, s);
            int mn = min(ss, s);
            same_max = max(same_max, mx + (mn / 2));
            A[f] = mx;
        }
    }

    // solve
    int mx = 0;
    int diff_max = 0;
    vector<int> tmp;
    for (auto& [key, value]: A) {
        tmp.push_back(value);
    }

    sort(rall(tmp));

    diff_max = tmp[0] + tmp[1];

    // output
    cout << max(same_max, diff_max) << endl;
}