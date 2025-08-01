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
#define double long double
using mint = modint998244353;
template <class T>
using V = vector<T>;
template <class T>
using P = pair<T, T>;
template <class T>
using PQ = priority_queue<T>;
template <class T>
using PQG = priority_queue<T, V<T>, greater<T>>;
const long long INF = LLONG_MAX;
const long long MIN_INF = LLONG_MIN;

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

signed main()
{
    // input
    int T;
    cin >> T;
    V<int> Ans(T);
    rep(i, T)
    {
        int N, M;
        cin >> N >> M;
        V<int> AmodM(N);
        V<int> BmodM(N);
        int C = 0;
        int sumAB = 0;
        rep(j, N)
        {
            int a;
            cin >> a;
            C += a / M;
            AmodM[j] = a % M;
            sumAB += a;
        }
        rep(j, N)
        {
            int b;
            cin >> b;
            C += b / M;
            BmodM[j] = b % M;
            sumAB += b;
        }
        sort(rall(AmodM));
        sort(all(BmodM));
        int idx_b = 0;
        rep(idx_a, N)
        {
            if (idx_b >= N)
                break;
            int a = AmodM[idx_a];
            int b = BmodM[idx_b];
            // cout << "a: " << a << ", b: " << b << endl;
            while (a + b < M && idx_b < N - 1)
            {
                idx_b++;
                b = BmodM[idx_b];
            }
            // cout << "a: " << a << ", b: " << b << endl;
            if (a + b >= M)
                C++;
            idx_b++;
        }
        Ans[i] = sumAB - C * M;
    }

    // output
    for (const auto &ans : Ans)
        cout << ans << endl;
}