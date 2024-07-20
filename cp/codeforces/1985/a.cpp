#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  string a{}, b{};
  cin >> a >> b;

  char tmp{a[0]};
  a[0] = b[0];
  b[0] = tmp;

  cout << a << ' ' << b << '\n';
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
