#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll l{}, r{};
  cin >> l >> r;
  if(r - l >= 10 || (l / 10) % 10 != (r / 10) % 10) {
    cout << 0 << '\n';
    return;
  }
  

  ll res{1};
  while(l > 0) {
    res *= l % 10;
    l /= 10;
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
