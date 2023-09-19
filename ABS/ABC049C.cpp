#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    string S;
    cin >> S;
    map<string, int> m{{"dream", 5}, {"dreamer", 7}, {"erase", 5}, {"eraser", 6}};
    stack<int> st({0});
    int start;
    int end;
    string ans = "NO";
    while (!st.empty()) {
        start = st.top();
        st.pop();
        if (start == S.size()) {
            ans = "YES";
            break;
        }
        for (auto [key, value]: m) {
            if (key == S.substr(start, value)) {
                st.push(start+value);
            }
        }
    }
    cout << ans << endl;
}