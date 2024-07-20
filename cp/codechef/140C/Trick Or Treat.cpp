#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  map<ll, ll> mp{};
  for(int i{}; i < n; ++i) {
    ll x{};
    cin >> x;

    ++mp[x % m];
  }

  ll res{};
  for (size_t i = 0; i < n; i++) {
    ll x{};
    cin >> x;

    res += mp[(m - (x % m)) % m];
    /*++mp[x % m];*/
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

