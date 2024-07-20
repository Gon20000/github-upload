#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  int res{}, res2{};
  for(int i{n - 1}; i >= 1; --i) {
    int x{gcd(i, n) + i};
    if(res <= x) {
      res = x;
      res2 = i;
    }
  }

  cout << res2 << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;
  while(t--)
      solve();

  return 0;
}
