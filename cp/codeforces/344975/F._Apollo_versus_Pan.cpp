#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll mod{static_cast<ll>(1e9) + 7};

ll add(ll x, ll y) {
  return (x % mod + y % mod) % mod;
}

ll mult(ll x, ll y) {
  return ((x % mod) * (y % mod)) % mod;
}

ll getOr(int j, const vector<ll>& arr, const vector<ll>& cnt) {
  ll res{};
  for(ll x{}; x < 60; ++x) {
    if(arr[j] & (1ll << x))
      continue;

    res = add(res, mult((1ll << x),  cnt[x]));
  }

  return add(res, mult(arr[j], arr.size()));
}

ll getAnd(int i, const vector<ll>& arr, const vector<ll>& cnt) {
  ll res{};

  for(ll x{}; x < 60; ++x) {
    if(!(arr[i] & (1ll << x)))
      continue;

    res = add(res, mult(1ll << x, cnt[x]));
  }

  return res;
}

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n), cnt(61);
  for(ll& x : arr) {
    cin >> x;
    for(int i{}; i < 60; ++i)
      if(x & (1ll << i))
        ++cnt[i];
  }

  ll res{};
  for(int j{}; j < n; ++j) {
    res = add(res, mult(getOr(j, arr, cnt), getAnd(j, arr, cnt)));
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

