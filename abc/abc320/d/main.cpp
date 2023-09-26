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
    int N, M; cin >> N >> M;
    vector<map<int, pair<int, int>>> ABXY(N+1);
    rep (i, M) {
        int a, b, dx, dy;
        cin >> a >> b >> dx >> dy;
        ABXY[a][b] = make_pair(dx, dy);
        ABXY[b][a] = make_pair(-dx, -dy);
    }

    set<int> s;
    s.insert(1);
    stack<int> st;
    st.push(1);
    vector<pair<ll, ll>> pos(N+1);
    pos[1] = make_pair(0, 0);
    while (!st.empty()) {
        int a = st.top();
        st.pop();
        map<int, pair<int, int>> BXY = ABXY[a];
        auto begin = BXY.begin();
        auto end = BXY.end();
        for (auto iter = begin; iter != end; iter++) {
            int b = iter->first;
            if (s.count(b) == 0) {
                st.push(b);
                s.insert(b);

                int dx = iter->second.first;
                int dy = iter->second.second;
                pos[b] = make_pair(pos[a].first + dx, pos[a].second + dy);
            }
        }
    }

    rep (i, N) {
        if (s.count(i+1) == 0) {
            cout << "undecidable" << endl;
        } else {
            cout << pos[i+1].first << ' ' << pos[i+1].second << endl;
        }
    }
}