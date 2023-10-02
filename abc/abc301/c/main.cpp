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
    string S, T; cin >> S >> T;

    // solve
    set<char> list = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    multiset<char> SS;
    multiset<char> TT;
    multiset<char> diffs;
    multiset<char> difft;
    multiset<char> diff;
    int c = 0;
    rep (i, S.size()) {
        if (S[i] != '@') {
            SS.insert(S[i]);
        } else {
            c++;
        }
    }
    rep (i, T.size()) {
        if (T[i] != '@') {
            TT.insert(T[i]);
        } else {
            c++;
        }
    }

    set_difference(all(SS), all(TT), inserter(diffs, diffs.end()));
    set_difference(all(TT), all(SS), inserter(difft, difft.end()));
    set_union(all(diffs), all(difft), inserter(diff, diff.end()));

    string ans = "Yes";
    if (c < diff.size()) {
        ans = "No";
    } else {
        for (auto& d: diff) {
            if (list.count(d) == 0) {
                ans = "No"; 
                break;
            }
        }
    }

    // output
    cout << ans << endl;
}