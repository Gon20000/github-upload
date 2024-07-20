#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  map<ll, ll> mp{};
  ++mp[0];
  ll curr{}, res{};
  for(int i{}; i < n; ++i) {
    ll x{};
    cin >> x;
    curr += x;
    curr = (curr % n + n) % n;

    res += mp[curr];
    ++mp[curr];
  }

  cout << res << '\n';
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

