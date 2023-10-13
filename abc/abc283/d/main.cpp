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

signed main() {
    // input
    string S; cin >> S;

    // solve
    stack<char> st;
    set<char> box;
    string ans = "Yes";
    rep (i, S.size()) {
        if (S[i] == '(') {
            st.push(S[i]);
        } else if (S[i] == ')') {
            while (true) {
                char c = st.top();
                st.pop();
                if (c == '(') {
                    break;
                } else if (c != ')') {
                    box.erase(c);
                }
            }
        } else {
            st.push(S[i]);
            if (box.count(S[i]) != 0) {
                ans = "No";
                break;
            } else {
                box.insert(S[i]);
            }
        }
    }

    // output
    cout << ans << endl;
}