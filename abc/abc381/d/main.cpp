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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        int a;
        cin >> a;
        A[i] = a;
    }

    // solve
    int ans = 0;
    int prev = A[0];
    int ct = 1;
    vector<P<int>> RLE;
    rep3(i, 1, N)
    {
        if (prev == A[i])
        {
            ct++;
        }
        else
        {
            RLE.push_back({prev, ct});
            prev = A[i];
            ct = 1;
        }
    }
    RLE.push_back({prev, ct});

    set<int> st;
    int idx = 0;
    rep(i, RLE.size())
    {
        int x = RLE[i].first;
        int ct = RLE[i].second;
        if (ct < 2)
        {
            st.clear();
            idx = i + 1;
        }
        else if (ct == 2 && st.count(x) == 0)
        {
            st.insert(x);
            ans = max(ans, (int)st.size());
        }
        else if (ct == 2)
        {
            ans = max(ans, (int)st.size());
            rep3(j, idx, i)
            {
                if (RLE[j].first == x)
                {
                    idx = j + 1;
                    break;
                }
                else
                {
                    st.erase(RLE[j].first);
                }
            }
        }
        else
        {
            if (st.count(x) == 0)
                ans = max(ans, (int)st.size() + 1);
            else
                ans = max(ans, (int)st.size());
            st.clear();
            st.insert(x);
            idx = i;
        }
    }
    ans = max(ans, (int)st.size());

    // output
    cout << ans * 2 << endl;
}