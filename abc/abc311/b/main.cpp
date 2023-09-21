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
    int N;
    size_t D; 
    cin >> N >> D;
    vector<bitset<100>> bit(N);
    rep(i, N) {
        rep (j, D) {
            char c;
            cin >> c;
            if (c == 'o') {
                bit.at(i).set(j);
            }
        }
    }
    bitset<100> ans;
    ans.set();
    for (auto b: bit) {
        ans = ans & b;
    }
    int count = 0;
    int max = 0;
    rep (i, 100) {
        if (ans[i]) {
            count++;
        } else {
            count = 0;
        }
        if (count > max) {
            max = count;
        }
    }
    
    // output
    cout << max << endl;
}