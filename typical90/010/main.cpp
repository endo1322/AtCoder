#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP(i,n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i,m,n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REPR(i,n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i,m,n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define ALL(x) std::begin(x), std::end(x)

vector<int64_t> solve(const vector<int64_t>q, const vector<vector <int64_t>>& sum) {
    vector<int64_t> s(2);
    s.at(0) += sum.at(0).at(q.at(1)) - sum.at(0).at(q.at(0)-1);
    s.at(1) += sum.at(1).at(q.at(1)) - sum.at(1).at(q.at(0)-1);
    return s;
}

int main() {
    // input
    int N; cin >> N;
    int c;
    vector<vector <int64_t>> P(2, vector<int64_t>(N+1, 0));
    REP (i, N) {
        cin >> c >> P.at(c-1).at(i+1);
    }
    int Q; cin >> Q;
    vector<vector <int64_t>> LR(Q, vector<int64_t>(2));
    REP (i, Q) {
        cin >> LR.at(i).at(0) >> LR.at(i).at(1);
    }

    // solve
    vector<vector <int64_t>> ans(Q, vector<int64_t>(2));
    vector<vector <int64_t>> sum(2, vector<int64_t>(N+1, 0));
    REP3 (i, 1, N+1) {
        sum.at(0).at(i) = sum.at(0).at(i-1) + P.at(0).at(i);
        sum.at(1).at(i) = sum.at(1).at(i-1) + P.at(1).at(i);
    }
    REP (i, Q) {
        ans.at(i) = solve(LR.at(i), sum);
    }

    // output
    REP (i, Q) {
        cout << ans.at(i).at(0) << ' ' << ans.at(i).at(1) << endl;
    }
}