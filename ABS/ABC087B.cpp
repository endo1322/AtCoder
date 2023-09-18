#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int A, B, C, X;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> X;
    int count = 0;
    rep(i, 0, A+1) {
        rep(j, 0, B+1) {
            rep(k, 0, C+1) {
                if (500 * i + 100 * j + 50 * k == X) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}