#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, 0, N) {
        cin >> A.at(i);
    }
    bool flag = true;
    int count = 0;
    while (flag) {
        count++;
        rep(i, 0, N) {
            if (A.at(i) % 2 != 0) {
                flag = false;
            }
            A.at(i) /= 2;
        }
    }
    cout << count - 1 << endl;
}
