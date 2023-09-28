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
    string S; cin >> S;
    int Q; cin >> Q;
    int flag = 1;
    int mem = 0;
    vector<int> T(N);
    map<int, pair<int, char>> change;
    rep (i, Q) {
        int t, x;
        char c;
        cin >> t >> x >> c;
        if (t == 1) {
            change[x-1] = make_pair(i, c);
        } else if (t == 2 || t == 3) {
            flag = t;
            mem = i;
        }
    }

    // solve
    string ans;
    int diff = 0;
    if (flag == 2) {
        diff = 32;
    } else if (flag == 3) {
        diff = -32;
    }
    rep (i, N) {
        if (change.count(i) == 0) {
            if (flag == 1) {
                ans += S[i];
            } else if (flag == 2) {
                if (islower(S[i])) ans += S[i]; else ans += S[i] + diff;
            } else {
                if (!islower(S[i])) ans += S[i]; else ans += S[i] + diff;
            }
        } else {
            if (change[i].first > mem) {
                ans += change[i].second;   
            } else {
                if (flag == 1) {
                    ans += change[i].second;
                } else if (flag == 2) {
                    if (islower(change[i].second)) ans += change[i].second; else ans += change[i].second + diff;
                } else {
                    if (!islower(change[i].second)) ans += change[i].second; else ans += change[i].second + diff;
                }
            }
        }
    }

    // output
    cout << ans << endl;
}