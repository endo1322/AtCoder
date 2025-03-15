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
using mint = modint;
template<class T> using V = vector<T>;
template<class T> using P = pair<T, T>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T,V<T>,greater<T>>;
const long long INF = LLONG_MAX;
const long long MIN_INF = LLONG_MIN;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

signed main() {
    // input
    int N; cin >> N;
    // mint::set_mod(360);
    PQG<int> pq;
    pq.push(0);
    int prev = 0;
    rep (i, N) {
        int a;
        cin >> a;
        prev += a;
        prev %= 360;
        pq.push(prev);
    }

    // solve
    int ans = MIN_INF;
    int first = pq.top();
    prev = first;
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        int diff = (top - prev) % 360;
        ans = max(ans, diff);
        prev = top;
    }
    // cout << first << " " << prev << endl;
    ans = max(ans, ((first - prev) % 360 + 360) % 360);

    // output
    cout << ans << endl;
}