#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  string op; 
  int B;
  int ans = A;
  for (int i = 0; i < N; i++) {
    cin >> op >> B;
    if (op == "+") {
        ans += B;
    } else if (op == "-") {
        ans -= B;
    } else if (op == "*") {
        ans *= B;
    } else if (op == "/") {
        if (B == 0) {
        cout << "error" << endl;
        i++;
        for (; i < N; i++) cin >> op >> B;
        break;
        } else {
            ans /= B;
        }
    }
    cout << i + 1 << ":" << ans << endl;
  }
}
