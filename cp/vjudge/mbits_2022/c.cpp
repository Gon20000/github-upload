#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  ld K{ld(k) / 2.0};
  vector<ll> arr(n);
  pair<ll, ld> res{0, LLONG_MAX};
  int i{};
  for(ll& x : arr) {
    cin >> x;
    ++i;
    x %= k;
      
    if(abs(x - K) <= res.second) {
      res = {i, abs(x - K)};
    }
  }

  cout << res.first << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;
  while(t--)
    solve();

  return 0;
}
