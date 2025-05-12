#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define rep3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define rrep(i, n) for (int i = (int)(n) - 1; (i) >= 0; --(i))
#define rrep3(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); --(i))
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)
#define int long long
#define ll long long
using mint = modint998244353;
template <class T>
using V = vector<T>;
template <class T>
using P = pair<T, T>;
template <class T>
using PQ = priority_queue<T>;
template <class T>
using PQG = priority_queue<T, V<T>, greater<T>>;
const long long INF = 1e18;
const long long MIN_INF = -1e18;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

int binary_search(int K, vector<int> &A, int L)
{
    int ng = L;
    int ok = 0;

    auto isOK = [&](int key) -> bool
    {
        int tmp = 0;
        int num = 0;
        for (auto a : A)
        {
            if (a - tmp >= key)
            {
                num++;
                tmp = a;
                if (num == K)
                    break;
            }
        }
        if (num == K && L - tmp >= key)
            return true;
        return false;
    };

    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;

        if (isOK(mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

signed main()
{
    // input
    int N, L;
    cin >> N >> L;
    int K;
    cin >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    // solve
    int ans = binary_search(K, A, L);

    // output
    cout << ans << endl;
}