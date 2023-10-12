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
#define int long long
#define ll long long

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<int> culc_p(int N) {
    vector<bool> isP(N, true);
    vector<int> P;
    isP[0] = isP[1] = false;
    rep3 (i, 2, N) {
        if (!isP[i]) continue;
        P.push_back(i);
        for (int j = 1; i * j < N; j++) {
            isP[i*j] = false;
        }
    }
    return P;
}

signed main() {
    // input
    int W, H; cin >> W >> H;
    int N; cin >> N;
    vector<pair<int, int>> PQ(N);
    rep (i, N) {
        int p, q;
        cin >> p >> q;
        PQ[i] = make_pair(p, q);
    }
    int AN; cin >> AN;
    vector<int> A(AN);
    rep (i, AN) {
        int a;
        cin >> a;
        A[i] = a;
    }
    int BN; cin >> BN;
    vector<int> B(BN);
    rep (i, BN) {
        int b;
        cin >> b;
        B[i] = b;
    }

    // solve
    int box_num = (AN + 1) * (BN + 1);
    map<pair<int, int>, int> Box;
    rep (i, N) {
        int p = PQ[i].first;
        int q = PQ[i].second;
        vector<int>::iterator itr_a = lower_bound(all(A), p);
        vector<int>::iterator itr_b = lower_bound(all(B), q);
        int a = itr_a - A.begin();
        int b = itr_b - B.begin();
        if (Box.count(make_pair(a, b)) == 0) {
            Box[make_pair(a, b)] = 1;
        } else {
            Box[make_pair(a, b)]++;
        }
    }

    int mn = LLONG_MAX;
    int mx = 0;
    for (auto itr = Box.begin(); itr != Box.end(); itr++) {
        mn = min(mn, itr->second);
        mx = max(mx, itr->second);
    }
    if (Box.size() < box_num) {
        mn = 0;
    }

    // output
    cout << mn << ' ' << mx << endl;
}