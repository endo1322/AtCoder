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
    V<int> Ans;
    V<int> Idx2Box(N);
    V<int> Box2Idx(N);
    V<int> Bird2Box(N);
    V<set<int>> Box(N);
    rep(i, N)
    {
        Idx2Box[i] = i;
        Bird2Box[i] = i;
        Box2Idx[i] = i;
        Box[i].insert(i);
    }
    rep(i, Q)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int boxA = Bird2Box[a];
            int boxB = Idx2Box[b];
            Box[boxA].erase(a);
            Box[boxB].insert(a);
            Bird2Box[a] = boxB;
        }
        else if (q == 2)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int boxA = Idx2Box[a];
            int boxB = Idx2Box[b];
            Idx2Box[a] = boxB;
            Idx2Box[b] = boxA;
            Box2Idx[boxA] = b;
            Box2Idx[boxB] = a;
        }
        else
        {
            int a;
            cin >> a;
            a--;
            int box = Bird2Box[a];
            int Idx = Box2Idx[box];
            Ans.push_back(Idx + 1);
        }
    }

    // output
    for (auto &a : Ans)
    {
        cout << a << endl;
    }
}