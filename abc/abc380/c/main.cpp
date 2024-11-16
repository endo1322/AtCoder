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
    int N, K; cin >> N >> K;
    string S; cin >> S;

    // solve
    int ans = 0;
    int tmp = 0;
    bool is_one = false;
    bool is_k = false;
    int is_prev = 0;
    int is_prev_last = 0;
    int is_k_prev = 0;
    int is_k_prev_last = 0;
    int is_k_ = 0;
    int is_k_last = 0;
    rep (i, N) {
        if (S[i] == '1' && !is_one) {
            is_one = true;
            tmp++;
            if (tmp == K) {
                is_k = true;
                is_k_ = i;
                is_k_prev = is_prev;
            } else {
                is_prev = i;
            }
        } else if (S[i] == '1' && is_one) {

        } else if (S[i] == '0' && is_one) {
            if (is_k) {
                is_k_last = i;
                is_k_prev_last = is_prev_last;
                break;
            }
            is_one = false;
            is_prev_last = i;
        }
    }

    if (is_k_last == 0) {
        is_k_last = N;
        is_k_prev_last = is_prev_last;
    }

    int k_len = is_k_last - is_k_;
    int prev_len = is_k_ - is_k_prev_last;
    // cout << prev_len << ' ' << k_len << endl;
    // cout << is_k_ << ' ' << is_k_prev_last << endl;

    string tmp_prev = S.substr(is_prev_last, prev_len);
    string tmp_ = S.substr(is_k_, k_len);
    S.erase(is_k_, k_len);
    S.insert(is_prev_last, k_len, '1');
    // S.replace(is_prev_last, k_len, tmp_);
    // S.replace(is_k_last - is_k, prev_len, prev_len, '0');
    // cout << prev_len;

    // output
    cout << S << endl;
}