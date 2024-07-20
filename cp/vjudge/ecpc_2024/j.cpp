#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ld x{}, y{};
  cin >> x >> y;

  x *= x;
  y *= y;

  cout << static_cast<ll>(ceil(sqrt(x + y))) << '\n';
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
