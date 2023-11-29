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
template<class T> using V = vector<T>;
template<class T> using P = pair<T, T>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T,V<T>,greater<T>>;
const long long INF = 1e18;
const long long MIN_INF = -1e18;

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

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

signed main() {
    // input
    int N, M, X; cin >> N >> M >> X;
    vector<pair<int, V<int>>> A(N);
    rep (i, N) {
        int c;
        cin >> c;
        A[i].first = c;
        rep (j, M) {
            int a;
            cin >> a;
            A[i].second.push_back(a);
        }
    }

    // solve
    int ans = INF;
    for (int bit = 0; bit < (1 << N); bit++) {
        V<int> tmp(M, 0);
        int tmp_sum = 0;
        rep (i, N) {
            if (bit & (1 << i)) {
                tmp_sum += A[i].first;
                rep (j, M) {
                    tmp[j] += A[i].second[j];
                }
            }
        }
        bool flag = true;
        rep (i, M) {
            if (tmp[i] < X) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = min(ans, tmp_sum);
        }
    }

    if (ans == INF) {
        ans = -1;
    }

    // output
    cout << ans << endl;
}