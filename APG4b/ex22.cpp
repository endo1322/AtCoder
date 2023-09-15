#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> p(N);
  rep(i, 0, N) {
      cin >> p.at(i).second >> p.at(i).first;
  }
  sort(p.begin(), p.end());

  rep(i, 0, N) {
    cout << p.at(i).second << " " << p.at(i).first << endl;
  }
}
