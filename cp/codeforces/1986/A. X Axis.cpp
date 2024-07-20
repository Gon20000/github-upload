#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll x{}, y{}, z{};
  cin >> x >> y >> z;

  ll res{INT_MAX};
  for(int i{}; i <= 10; ++i) {
    res = min(res, abs(x - i) + abs(y - i) + abs(z - i));
  }

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

