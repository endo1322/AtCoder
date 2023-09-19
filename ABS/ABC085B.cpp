#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> D(N);
    rep(i, 0, N) {
        cin >> D.at(i);
    }
    set<int> ans;
    for (int d: D) {
        ans.insert(d);
    }
    cout << ans.size() << endl;
}