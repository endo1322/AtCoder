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
    int N, M; cin >> N >> M;
    vector<pair<int, vector<int>>> vertex(N+1, pair<int, vector<int>>(0, vector<int>()));
    rep (i, M) {
        int a, b;
        cin >> a >> b;
        vertex.at(a).second.push_back(b);
        vertex.at(b).second.push_back(a);
        if (a > b) {
            vertex.at(a).first++;
        } else {
            vertex.at(b).first++;
        }
    }

    // solve
    int ans = 0;
    for (auto v: vertex) {
        if (v.first == 1) {
            ans++;
        }
    }

    // output
    cout << ans << endl;
}