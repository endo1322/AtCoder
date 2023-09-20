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
    set<string> S;
    vector<int> ans;
    rep (i, N) {
        string name;
        cin >> name;
        if (!S.count(name)) {
            ans.push_back(i+1);
            S.insert(name);
        }
    }

    // output
    rep (i, ans.size()) {
        cout << ans.at(i) << endl;
    }
}