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

int64_t solve(string S, set<char> C) {
    int64_t num = 0;
    for (auto s: S) {
        num++;
        C.insert(s);
        if (C.size() == 3) {
            return num;
        }
    }
}

int main() {
    // input
    int N; cin >> N;
    string S; cin >> S;
    set<char> C;

    // solve
    auto ans = solve(S, C);

    // output
    cout << ans << endl;
}