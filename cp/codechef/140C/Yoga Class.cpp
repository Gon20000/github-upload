#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n{}, x{}, y{};
    cin >> n >> x >> y;

    if(n < 2 || (2 * x >= y))
      cout << x * n << '\n';
    else
      cout << y * (n / 2) + x * (n % 2) << '\n';
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

