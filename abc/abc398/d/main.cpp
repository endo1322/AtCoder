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
    int N, R, C;
    cin >> N >> R >> C;
    string S;
    cin >> S;

    // solve
    string ans;
    P<int> fire_pos = {0, 0};
    P<int> man_pos = {C, R};
    set<P<int>> smoke_pos;
    smoke_pos.insert(fire_pos);
    for (auto c : S)
    {
        P<int> d;
        if (c == 'N')
        {
            d = {0, 1};
        }
        else if (c == 'S')
        {
            d = {0, -1};
        }
        else if (c == 'E')
        {
            d = {-1, 0};
        }
        else if (c == 'W')
        {
            d = {1, 0};
        }
        man_pos.first += d.first;
        man_pos.second += d.second;

        fire_pos.first += d.first;
        fire_pos.second += d.second;
        smoke_pos.insert(fire_pos);

        if (smoke_pos.count(man_pos))
            ans.push_back('1');
        else
            ans.push_back('0');
    }

    // output
    cout << ans << endl;
}