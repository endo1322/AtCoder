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
#define ll long long

int main() {
    // input
    int H, W; cin >> H >> W;
    int h, w;
    if (H % 2 == 0) {
        h = H / 2;
    } else {
        h = H / 2 + 1;
    }

    if (W % 2 == 0) {
        w = W / 2;
    } else {
        w = W / 2 + 1;
    }

    if (H == 1 or W == 1) {
         // output
        cout << H * W << endl;
    } else {
        cout << h * w << endl;
    }
}