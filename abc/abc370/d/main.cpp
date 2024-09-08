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

// int binary_search(int key, vector<int> &a) {
//     int ng = -1;
//     int ok = (int)a.size();

//     auto isOK = [&](int index) -> bool {
//         return a[index] >= key;
//     };

//     while (abs(ok - ng) > 1) {
//         int mid = (ok + ng) / 2;

//         if (isOK(mid)) ok = mid;
//         else ng = mid;
//     }
//     return ok;
// }

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
    int H, W, Q; cin >> H >> W >> Q;
    vector<pair<int, int>> RC(Q);
    rep (i, Q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        RC[i] = {r, c};
    }

    // solve
    int ans = H * W;
    set<pair<int, int>> hh;
    set<pair<int, int>> ww;
    rep (i, H) rep (j, W) {
        hh.insert({i, j});
        ww.insert({j, i});
    }
    rep (i, Q) {
        if (hh.count({RC[i]})) {
            hh.erase({RC[i]});
            ww.erase({RC[i].second, RC[i].first});
            std::cout << "yes" << ' ' << RC[i].first << ' ' << RC[i].second << endl;
        } else {
            auto next_h = hh.lower_bound({RC[i]});
            auto prev_h = (next_h == hh.begin()) ? hh.end() : std::prev(next_h);

            auto next_w = ww.lower_bound({RC[i].second, RC[i].first});
            auto prev_w = (next_w == ww.begin()) ? ww.end() : std::prev(next_w);

            // hh の要素を削除
            if (next_h != hh.end()) {
                auto next_h_val = *next_h;
                if (next_h_val.first == RC[i].first) {
                    hh.erase(next_h);
                    ww.erase(next_h_val);
                    std::cout << RC[i].first << ' ' << RC[i].second << ' ' <<  next_h_val.first << ' ' << next_h_val.second  << endl;
                }
            }
            if (prev_h != hh.end()) {
                auto prev_h_val = *prev_h;
                if (prev_h_val.first == RC[i].first) {
                    hh.erase(prev_h);
                    ww.erase(prev_h_val);
                    std::cout << RC[i].first << ' ' << RC[i].second << ' ' <<  prev_h_val.first << ' ' << prev_h_val.second  << endl;
                }
            }

            // ww の要素を削除
            if (next_w != ww.end()) {
                auto next_w_val = *next_w;
                if (next_w_val.first == RC[i].second) {
                    ww.erase(next_w);
                    hh.erase(next_w_val);
                    std::cout << RC[i].first << ' ' << RC[i].second << ' ' <<  next_w_val.second << ' ' << next_w_val.first  << endl;
                }
            }
            if (prev_w != ww.end()) {
                auto prev_w_val = *prev_w;
                if (prev_w_val.first == RC[i].second) {
                    ww.erase(prev_w);
                    hh.erase(prev_w_val);
                    std::cout << RC[i].first << ' ' << RC[i].second << ' ' <<  prev_w_val.second << ' ' << prev_w_val.first  << endl;
                }
            }
        }
    }

    // output
    std::cout << hh.size() << endl;
}