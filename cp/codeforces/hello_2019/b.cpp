#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, total{};
  cin >> n;

  vector<int> dirs(n);
  for(int& x : dirs) {
    cin >> x;
    total += x;
  }

  int subsets{1 << n};
  for(int i{0}; i < subsets; ++i) {
    int curr{};
    for(int j{}; j < n; ++j) {
      if((i >> j) & 1)
        curr -= dirs[j];
    }

    if((total + 2 * curr) % 360 == 0) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}
