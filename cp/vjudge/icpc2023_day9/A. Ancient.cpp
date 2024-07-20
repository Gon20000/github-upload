#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll add(ll x, ll y, ll m) {
  return (x % m + y % m) % m;
}

ll subtract(ll x, ll y, ll m) {
  return ((((x % m) - (y % m)) % m) + m) % m;
} 

ll mult(ll x, ll y, ll m) {
  return ((x % m) * (y % m)) % m;
}

void solve() {
  ll n{}, m{};
  cin >> n >> m;

  vector<ll> arr(n), pref(n);
  for(int i{}; i < n; ++i) {
    cin >> arr[i];

    pref[i] = arr[i];
    pref[i] %= m;

    if(i > 0)
      pref[i] = add(pref[i], pref[i - 1], m);
  }

  ll res{};
  for(int i{}; i < n - 1; ++i) {
    ll x{mult(arr[i], n - i - 1, m)};
    ll y{subtract(pref.back(), pref[i], m)};

    res += subtract(max(x, y), min(x, y), m);
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

