#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
  // ここにプログラムを追記
  int tmp = data.at(0);
  string ans = "NO";
  rep(i, 1, 5) {
    if (tmp == data.at(i)) {
        ans = "YES";
        break;
    }
    tmp = data.at(i);
  }
  cout << ans << endl;
}
