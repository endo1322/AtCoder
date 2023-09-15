#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int ans = 1;
  char op;

  // ここにプログラムを追記
  for (int i = 0; i < S.size() / 2; i++) {
    op = S.at(i * 2 + 1);
    if (op == '+') {
        ans += 1;
    } else if (op == '-') {
        ans -= 1;
    }
  }
  cout << ans << endl;
}
