#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    string ans = "Yes";
    int t, x, y;
    int prev_pos = 0, prev_step = 0;
    rep(i, 0, N) {
        cin >> t >> x >> y;
        if (!((t - prev_step) >= abs(prev_pos - (x + y)) and (t + x + y) % 2 == 0)) {
            ans = "No";
        }
        prev_pos = x + y;
        prev_step = t;
    }
    cout << ans << endl;
}