#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using mouse_t = pair<ll, string>;

void solve() {
  int a{}, b{}, c{}, m{};
  cin >> a >> b >> c >> m;

  pair<ll, ll> res{};
  vector<mouse_t> arr(m);
  for(mouse_t& x : arr)
    cin >> x.first >> x.second;

  sort(arr.begin(), arr.end());

  for(auto [price, type] : arr) {
    if(type[0] == 'U') {
      if(a) {
        --a;
        res.first += price;
        ++res.second;
      }
      else if(c) {
        --c;
        res.first += price;
        ++res.second;
      }
    }
    else {
      if(b) {
        --b;
        res.first += price;
        ++res.second;
      }
      else if(c) {
        --c;
        res.first += price;
        ++res.second;
      }
    }
  }
  cout << res.second << ' ' << res.first << '\n';
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

