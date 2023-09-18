#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    string S;
    cin >> S;
    int c = 0;
    for (char s: S) {
        if (s == '1') {
            c++;
        }
    }
    cout << c << endl;
}