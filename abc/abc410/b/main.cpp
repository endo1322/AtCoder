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
    int N, Q;
    cin >> N >> Q;
    // vector<int> A(N);
    // PQG<pair<int, int>> box;
    vector<int> box(N, 0);
    // rep (i, N) {
    //     box.insert({i, 0});
    // }
    vector<int> ans(Q);
    rep(i, Q)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            int mn = INF;
            rep(j, N)
            {
                mn = min(mn, box[j]);
            }
            int box_id = -1;
            rep(j, N)
            {
                if (box[j] == mn)
                {
                    box_id = j;
                    break;
                }
            }
            ans[i] = box_id + 1;
            box[box_id]++;
        }
        else
        {
            ans[i] = a;
            box[a - 1]++;
        }
    }

    // output
    rep(i, Q)
    {
        cout << ans[i];
        if (i == Q - 1)
            cout << endl;
        else
            cout << " ";
    }
}