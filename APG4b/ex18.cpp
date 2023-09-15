#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)
  vector<vector<char>> ans(N, vector<char>(N, '-'));
  int win, lose;
  rep(i, 0, M) {
    win = A.at(i);
    lose = B.at(i);
    ans.at(win-1).at(lose-1) = 'o';
    ans.at(lose-1).at(win-1) = 'x';
  }
  rep (i, 0, N) {
    rep (j, 0, N) {
        cout << ans.at(i).at(j);
        if (j == N - 1) break;
        cout << ' ';
    }
    cout << endl;  // それ以外なら空白
  }
}
