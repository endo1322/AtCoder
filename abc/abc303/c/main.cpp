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
    int N, M, H, K; cin >> N >> M >> H >> K;
    string S; cin >> S;
    set<pair<int, int>> se;
    rep (i, M) {
        int x, y;
        cin >> x >> y;
        se.insert(make_pair(x, y));
    }

    // solve
    string ans = "Yes";
    pair<int, int> st = make_pair(0, 0);
    int h = H;
    rep (i, N) {
        char c = S[i];
        int x = st.first;
        int y = st.second;

        if (c == 'R') x++;
        else if (c == 'L') x--;
        else if (c == 'U') y++;
        else y--;

        h--;

        st = make_pair(x, y);

        if (h < 0) {
            ans = "No";
            break;
        }
        if (se.count(st) != 0 && h < K) {
            h = K;
            se.erase(st);
        }
    }

    // output
    cout << ans << endl;
}