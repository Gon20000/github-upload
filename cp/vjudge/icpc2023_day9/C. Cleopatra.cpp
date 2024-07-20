#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll mod{5};

ll add(ll x, ll y) {
  return (x % mod + y % mod) % mod;
}

ll modpow(ll base, ll power) {
  if(power == 0)
    return 1 % mod;

  ll u{modpow(base, power / 2)};
  u = (u * u) % mod;

  if(power % 2 == 1)
    u = (u * base) % mod;

  return u % mod;
}

void solve() {
  string n{};
  cin >> n;

  int start{max(0, (int)n.size() - 2)};

  ll num{stoi(n.substr(start, 2))};
  cout << (num % 4 ? 0 : 4) << '\n';
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

