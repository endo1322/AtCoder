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
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<int> culc_p(int N) {
    vector<bool> isP(N, true);
    vector<int> P;
    isP[0] = isP[1] = false;
    rep3 (i, 2, N) {
        if (!isP[i]) continue;
        P.push_back(i);
        for (int j = 1; i * j < N; j++) {
            isP[i*j] = false;
        }
    }
    return P;
}

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

signed main() {
    // input
    int N; cin >> N;
    map<string, int> name_map;
    vector<pair<string, string>> name_vec(N);
    rep (i, N) {
        string s, t;
        cin >> s >> t;
        if (name_map.count(s) != 0) {
            name_map[s]++;
        } else {
            name_map[s] = 1;
        }
        if (name_map.count(t) != 0) {
            name_map[t]++;
        } else {
            name_map[t] = 1;
        }
        name_vec[i] = make_pair(s, t);
    }

    // solve
    string ans = "Yes";
    rep (i, N) {
        string sei = name_vec[i].first;
        string mei = name_vec[i].second;
        name_map[sei]--;
        name_map[mei]--;
        if (!(name_map[sei] == 0 || name_map[mei] == 0)) {
            ans = "No";
            break;
        }
        name_map[sei]++;
        name_map[mei]++;
    }

    // output
    cout << ans << endl;
}