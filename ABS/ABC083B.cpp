#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> ans;
    rep(i, 0, N+1) {
        string value = to_string(i);
        int v = 0;
        int tmp = 0;
        rep(j, 0, value.size()) {
            tmp += (value.at(j) - '0');
            v += (value.at(j) - '0') * pow(10, value.size()-j-1);
        }
        if (tmp >= A and tmp <= B) {
            ans.push_back(v);
        }
    }
    cout << accumulate(ans.begin(), ans.end(), 0) << endl;
}