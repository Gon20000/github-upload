#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll l{}, r{};
  cin >> l >> r;

  l ^= r;
  for(ll i{0}; i < 32; ++i) {
    if((l & (1LL << i)) != 0)  {
      cout << (1LL << i) << '\n';
      break;
    }
  }
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
