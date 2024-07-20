#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  set<ll> s{};
  while(m--) {
    ll x{};
    cin >> x;

    s.insert(x);
  }

  for(int i{1}; i <= n; ++i) {
    ll x{*s.lower_bound(i)};
    cout << x - i << '\n';
  }
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

