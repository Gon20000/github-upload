#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("pairup.in", "r", stdin);
  freopen("pairup.out", "w", stdout);

  int n{};
  cin >> n;

  map<ll, ll> mp{};

  while(n--) {
    ll x{}, y{};
    cin >> x >> y;

    mp[y] += x;
  }

  auto l{mp.begin()}, r{--mp.end()};
  ll res{};
  while(l != r) {
    ll a{min(l->second, r->second)};

    res = max(res, l->first + r->first);
    l->second -= a;
    r->second -= a;

    if(l->second == 0) {
      ++l;
    }

    if(l == r)
      break;

    if(r->second == 0)
      --r;
  }

  if(l->second > 0)
    res = max(res, l->first * 2);

  cout << res << '\n';

  return 0;
}
