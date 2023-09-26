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
    string S; cin >> S;

    int max = 0;
    rep(i, S.size()) {
        rep(j, S.size()) {
            string substr1 = S.substr(i, S.size()-j);
            string substr2 = substr1;
            reverse(all(substr2));
            if (substr1 == substr2) {
                int tmp = substr1.size();
                if (tmp > max) {
                    max = tmp;
                }
            }
        }
    } 

    // output
    cout << max << endl;
}