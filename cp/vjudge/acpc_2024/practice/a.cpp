#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int a{}, b{};
  cin >> a >> b;

  cout << (gcd(a, b) == 1 ? "NO" : "YES") << '\n';
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
