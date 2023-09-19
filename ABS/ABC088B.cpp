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
    sort(A.rbegin(), A.rend());
    int a = 0, b = 0;
    rep(i, 0, N) {
        if (i % 2 == 0) {
            a += A.at(i);
        } else {
            b += A.at(i);
        }
    }
    cout << a - b << endl;
}