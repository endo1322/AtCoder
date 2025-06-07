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
    vector<string> Ans(T);
    rep(i, T)
    {
        int N;
        cin >> N;
        string ans = "";
        char prev;
        // int mn = INF;
        int j = 0;
        while (j < N)
        {
            char c;
            cin >> c;
            if (j == 0)
            {
                ans += c;
                prev = c;
                j++;
                continue;
            }
            if (c >= prev)
            {
                ans += c;
                prev = c;
                j++;
            }
            else
            {
                // cout << "prev: " << prev << endl;
                string tmp = "";
                tmp += c;
                j++;
                while (j < N)
                {
                    char next_c;
                    cin >> next_c;
                    // cout << "prev: " << prev << endl;
                    if (prev >= next_c)
                    {
                        tmp += next_c;
                        j++;
                    }
                    else
                    {
                        // cout << "prev: " << prev << endl;
                        tmp += prev;
                        tmp += next_c;
                        prev = ' ';
                        j++;
                        break;
                    }
                }
                if (j == N && prev != ' ')
                {
                    tmp += prev;
                }
                ans.pop_back();
                ans += tmp;
                while (j < N)
                {
                    char next_c;
                    cin >> next_c;
                    ans += next_c;
                    j++;
                }
            }
        }
        Ans[i] = ans;
    }

    // output
    rep(i, T)
    {
        cout << Ans[i] << endl;
    }
}