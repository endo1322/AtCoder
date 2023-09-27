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

vector<char> no = {'a', 'e', 'i', 'o', 'u'};

signed main() {
    // input
    string S; cin >> S;

    // solve
    string ans;
    rep (i, S.size()) {
        rep (j, no.size()) {
            S.erase(remove(all(S), no[j]), S.end());
        }
    }

    // output
    cout << S << endl;
}