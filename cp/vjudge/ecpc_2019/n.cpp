#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int a{}, b{}, c{};
  cin >> a >> b >> c;

  cout << (a == b || a == c || b == c ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("equal.in", "r", stdin);

  int t{};
  cin >> t;

  while(t--)
    solve();

  return 0;
}
