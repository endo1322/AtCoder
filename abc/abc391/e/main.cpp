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

// めぐる式二分探索
// (ng, ok], [ok, ng) で考える
// https://qiita.com/drken/items/97e37dd6143e33a64c8c#2-%E4%B8%80%E8%88%AC%E5%8C%96%E3%81%97%E3%81%9F%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2%E6%B3%95
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
    int N; cin >> N;
    string S; cin >> S;
    vector<vector<pair<bool, int>>> G(N);
    rep (i, pow(3, N) / 3) {
        int ct = 0, ct_0 = 0, ct_1 = 0;
        bool flag_1;
        rep (j, 3) {
            char c = S[i * 3 + j];
            int a = c - '0';
            if (a == 0) ct_0++;
            else ct_1++;
        }
        if (ct_0 > ct_1) {
            flag_1 = false;
            if (ct_0 == 3) ct = 2;
            else ct = 1;
        } else {
            flag_1 = true;
            if (ct_1 == 3) ct = 2;
            else ct = 1;
        }
        G[0].push_back({flag_1, ct});
    }

    // solve
    rep3 (i, 1, N) {
        rep (j, pow(3, N - i) / 3) {
            bool next_flag1;
            int ct = INF, ct_0 = 0, ct_1 = 0;
            rep (k, 3) {
                auto flag_1 = G[i-1][j * 3 + k].first;
                if (flag_1) {
                    ct_1++;
                } else {
                    ct_0++;
                }
            }
            if (ct_0 > ct_1) {
                next_flag1 = false;
                if (ct_0 == 3) {
                    rep (k, 3) {
                        rep3 (l, k+1, 3) {
                            if (G[i-1][j * 3 + k].first == G[i-1][j * 3 + l].first) {
                                ct = min(ct, G[i-1][j * 3 + k].second +  G[i-1][j * 3 + l].second);
                            }
                        }
                    }
                } else {
                    rep (k, 3) {
                        if (G[i-1][j * 3 + k].first == false) {
                            ct = min(ct, G[i-1][j * 3 + k].second);
                        }
                    }

                }
                G[i].push_back({next_flag1, ct});
            } else {
                next_flag1 = true;
                if (ct_1 == 3) {
                    rep (k, 3) {
                        rep3 (l, k+1, 3) {
                            if (G[i-1][j * 3 + k].first == G[i-1][j * 3 + l].first) {
                                ct = min(ct, G[i-1][j * 3 + k].second +  G[i-1][j * 3 + l].second);
                            }
                        }
                    }
                } else {
                    rep (k, 3) {
                        if (G[i-1][j * 3 + k].first == true) {
                            ct = min(ct, G[i-1][j * 3 + k].second);
                        }
                    }
                }
                G[i].push_back({next_flag1, ct});
            }
        }
    }

    // output
    cout << G[N-1][0].second << endl;
}