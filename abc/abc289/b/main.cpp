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

vector<pair<int, int>> D4 = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
vector<pair<int, int>> D8 = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

vector<int> culc_p(int N) {
    vector<bool> isP(N, true);
    vector<int> P;
    isP[0] = isP[1] = false;
    rep3 (i, 2, N) {
        if (!isP[i]) continue;
        P.push_back(i);
        for (int j = 1; i * j < N; j++) {
            isP[i*j] = false;
        }
    }
    return P;
}

signed main() {
    // input
    int N, M; cin >> N >> M;
    vector<vector<int>> A;
    int ct = 1;
    int k = 0;
    if (M != 0) {
        rep (i, M) {
            int a;
            cin >> a;
            vector<int> tmp;
            if (i == 0) {
                if (ct == a) {
                    tmp.push_back(a);
                    A.push_back(tmp);
                    ct++;
                    k++;
                } else {
                    vector<int> tmp2;
                    rrep3 (j, ct, a) {
                        tmp2.push_back(j);
                    }
                    A.push_back(tmp2);
                    tmp.push_back(a);
                    A.push_back(tmp);
                    ct = a + 1;
                    k += 2;
                }
            } else {
                if (ct == a) {
                    A[k-1].push_back(ct);
                    ct++;
                } else {                    
                    A[k-1].push_back(ct);
                    ct++;
                    if (a - ct >= 1) {
                        vector<int> tmp2;
                        rrep3 (j, ct, a) {
                            tmp2.push_back(j);
                        }
                        A.push_back(tmp2);
                        k++;
                    }
                    tmp.push_back(a);
                    A.push_back(tmp);
                    ct = a + 1;
                    k++;
                }
            }
        }
        A[k-1].push_back(ct);
        ct++;
        if (N - ct >= 0) {
            vector<int> tmp2;
            rrep3 (j, ct, N+1) {
                tmp2.push_back(j);
            }
            A.push_back(tmp2);
            k++;
        }
    } else {
        vector<int> tmp;
        rrep3 (i, 1, N+1) {
            tmp.push_back(i);
        }
        A.push_back(tmp);
    }

    // solve
    vector<int> ans;
    for (auto a: A) {
        rrep (i, a.size()) {
            ans.push_back(a[i]);
        }
    }

    // output
    rep (i, N) {
        cout << ans[i];
        if (i < N - 1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }
}