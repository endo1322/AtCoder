#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int N, Y;
    cin >> N >> Y;
    int f = Y / 10000;
    int g = Y / 5000;
    int n;
    int y, max, mini;
    int ans_f = -1, ans_g = -1, ans_n = -1;
    rep(i, 0, f+1) {
        y = Y - (10000 * i);
        if (y < 0) {
            break;
        } else if (y == 0 and i == N) {
            ans_f = i;
            ans_g = 0;
            ans_n = 0;
            break;
        }
        rep(j, 0, g+1) {
            y = Y - (10000 * i) - (5000 * j);
            if (y < 0) {
                continue;
            } else if (y == 0 and ((i + j) == N)) {
                ans_f = i;
                ans_g = j;
                ans_n = 0;
                break;
            }
            n = (Y - (10000 * i) - (5000 * j)) / 1000;
            if ((i + j + n) == N) {
                ans_f = i;
                ans_g = j;
                ans_n = n;
                break;
            }
        }
    }
    cout << ans_f << ' ' << ans_g << ' ' << ans_n << endl;
}