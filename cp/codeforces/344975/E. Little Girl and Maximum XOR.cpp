#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll l{}, r{};
  cin >> l >> r;

  ll num{};
  for(int i{63 - __builtin_clzll(r)}; i >= 0; --i) {
    ll x{1ll << i};
    
    if(r - l >= x || ((l & x) ^ (r & x)))
      num ^= (1ll << i);
  }

  cout << num << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

