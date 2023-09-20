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
    int N; cin >> N;
    vector<vector<int64_t>> TX(N, vector<int64_t>(2));
    rep (i, N) {
        cin >> TX.at(i).at(0) >> TX.at(i).at(1);
    }

    // solve
    list<int64_t> deck;
    int64_t t, x, a;
    vector<int64_t> ans;
    rep (i, N) {
        t = TX.at(i).at(0);
        x = TX.at(i).at(1);
        if (t == 1) {
            deck.push_front(x);
        } else if (t == 2) {
            deck.push_back(x);
        } else {
            decltype(deck):: iterator it = deck.begin();
            advance(it, x-1);
            ans.push_back(*it);
        }
    }

    // output
    for (auto a: ans) {
        cout << a << endl;
    }
}