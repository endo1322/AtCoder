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

int binary_search(int key, vector<int> &a)
{
    int ng = -1;
    int ok = (int)a.size();

    auto isOK = [&](int index) -> bool
    {
        return a[index] >= key;
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
    int N;
    cin >> N;

    // solve
    int ans = 0;
    rep3(a, 1, 61)
    {
        int two_a = powl(2, a);
        int a_max = N / two_a;
        if (a_max == 0)
            break;
        int rest = N / two_a;
        double sqrt_rest = sqrt(rest);
        int b = static_cast<int>(sqrt_rest);
        if (two_a * powl(b, 2) > N)
            b--;
        double num_2 = log2(b);
        int num_2_int = static_cast<int>(num_2);
        // cout << two_a << " " << b << ' ' << num_2_int << endl;

        // if (num_2_int == num_2)
        //     num_2_int++;
        // b -= num_2;
        // if (b == 1)
        //     break;
        // cout << two_a << " " << b << ' ' << num_2 << endl;
        // cout << ceil((double)b / 2) << endl;
        ans += ceil((double)b / 2);
        // rep(b, sqrt_rest_int + 1)
        // {
        //     int x = two_a * powl(b, 2);
        //     if (x > N)
        //         break;
        //     if (x == 0)
        //         continue;
        //     ans.insert(x);
        // }
    }

    // output
    cout << ans << endl;
}