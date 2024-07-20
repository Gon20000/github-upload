#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, q{};
  cin >> n >> q;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  while(q--) {
    ll res{INT_MAX};
    int x{}, y{};
    cin >> x >> y;

    for(int i{x}; i < y; ++i) {
      res = min(arr[i], res);
    }

    cout << res << '\n';
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

