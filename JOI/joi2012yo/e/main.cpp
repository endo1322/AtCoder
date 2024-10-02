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
#define double long double
using mint = modint998244353;
template<class T> using V = vector<T>;
template<class T> using P = pair<T, T>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T,V<T>,greater<T>>;
const long long INF = LLONG_MAX;
const long long MIN_INF = LLONG_MIN;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D6_even = {{-1, -1}, {-1, 0}, {0, 1}, {1, 0}, {1, -1}, {0, -1}};
vector<pair<int, int>> D6_odd = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {0, -1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

set<int> culc_p(int N) {
    vector<bool> isP(N+1, true);
    set<int> P;
    isP[0] = isP[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!isP[i]) continue;
        for (int j = i * i; j <= N; j += i) isP[j] = false;
    }
    rep3 (i, 2, N+1) if (isP[i]) P.insert(i);
    return P;
}

int binary_search(int key, vector<int> &a) {
    int ng = -1;
    int ok = (int)a.size();

    auto isOK = [&](int index) -> bool {
        return a[index] >= key;
    };

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

pair<int, int> add_pair(const pair<int, int>& p1, const pair<int, int>& p2) {
    pair<int, int> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

int binaryToDecimal(const string& S) {
    int res = 0;
    for (char c: S) res = res * 2 + (c - '0');
    return res;
}

signed main() {
    // input
    int W, H; cin >> W >> H;
    vector<vector<int>> G(H, vector<int>(W));
    rep (i, H) {
        rep (j, W) {
            cin >> G[i][j];
        }
    }

    // solve
    int ans = 0;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pair<int, int>> que;
    rep (i, H) {
        rep (j, W) {
            if (visited[i][j]) continue;

            if (G[i][j] == 1) que.push({i, j});

            while (!que.empty()) {
                auto [ci, cj] = que.front(); que.pop();
                if (visited[ci][cj]) continue;
                visited[ci][cj] = true;

                if (ci % 2 == 0) {
                    for (auto d: D6_odd) {
                        int ni = ci + d.first;
                        int nj = cj + d.second;
                        if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                            ans++;
                            continue;
                        }
                        if (G[ni][nj] == 0) ans++;
                        else que.push({ni, nj});
                    }
                } else {
                    for (auto d: D6_even) {
                        int ni = ci + d.first;
                        int nj = cj + d.second;
                        if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                            ans++;
                            continue;
                        }
                        if (G[ni][nj] == 0) ans++;
                        else que.push({ni, nj});
                    }
                }
            }
        }
    }


    que = queue<pair<int, int>>();
    rep (i, H) {
        rep (j, W) {
            if (visited[i][j]) continue;

            if (G[i][j] == 0) que.push({i, j});

            bool is_minus = true;
            int minus = 0;
            while (!que.empty()) {
                auto [ci, cj] = que.front(); que.pop();
                if (visited[ci][cj]) continue;
                visited[ci][cj] = true;

                if (ci % 2 == 0) {
                    for (auto d: D6_odd) {
                        int ni = ci + d.first;
                        int nj = cj + d.second;
                        if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                            is_minus = false;
                            continue;
                        }
                        if (G[ni][nj] == 1) minus++;
                        else que.push({ni, nj});
                    }
                } else {
                    for (auto d: D6_even) {
                        int ni = ci + d.first;
                        int nj = cj + d.second;
                        if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                            is_minus = false;
                            continue;
                        }
                        if (G[ni][nj] == 1) minus++;
                        else que.push({ni, nj});
                    }
                }
            }
            if (is_minus) ans -= minus;
        }
    }

    // output
    cout << ans << endl;
}