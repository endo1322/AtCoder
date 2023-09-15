#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int sum = 0;
  int ave, ans;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  ave = sum / N;
  for (int i = 0; i < N; i++) {
    ans = ave - A.at(i);
    if (ans < 0) {
        ans = -ans;
    }
    cout << ans << endl;
  }
}
