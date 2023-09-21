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
    int N; cin >> N;
    vector<int64_t> A(N);
    rep (i, N) {
        cin >> A.at(i);
    }

    set<int> S;

    // solve
    int start = 1;
    while (true) {
        start = A.at(start - 1);
        if (S.count(start)) break;
        S.insert(start);
    }

    vector<int> ans({start});
    int st = start - 1;
    while (A.at(st) != start) {
        ans.push_back(A.at(st));
        st = A.at(st) - 1;
    }

     // output
    cout << ans.size() << endl;
    rep (i, ans.size()) {
        cout << ans.at(i);
        if (i < ans.size() - 1) cout << ' ';
    }
    cout << endl;
}