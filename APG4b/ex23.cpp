#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) {
    cin >> A.at(i);
  }
  map<int, int> M;
  for (int a : A) {
    if (M.count(a)) {
        M[a]++;
    } else {
        M[a] = 1;
    }
  }
  
  int max = 0;
  int ansKey = -1;
  int ansValue = 0;
  for (auto value: M) {
    if (max < value.second) {
        ansKey = value.first;
        ansValue = value.second;
        max = ansValue;
    }
  }
  cout << ansKey << ' ' << ansValue << endl;
}
