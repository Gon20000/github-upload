#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, q{};
  cin >> n >> q;

  vector<ll> diff(n + 1), psum(n);
  while(q--) {
    ll x{}, y{};
    cin >> x >> y;
    --x; --y;

    ++diff[x];
    --diff[y + 1];
  }

  psum[0] = diff[0];
  for(int i{1}; i < n; ++i) {
    psum[i] = psum[i - 1] + diff[i];
  }

  sort(psum.begin(), psum.end());
  cout << psum[n / 2] << '\n';
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

