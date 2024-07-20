#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, d{};
  cin >> n >> d;

  ll curr{d}, res{1};
  ll idx{0};
  for(int i{1}; i <= n; ++i) {
    ll x{}, num{};
    cin >> x;

    ++idx;
    if(idx % 2 == 0)
      num += (idx / 2) * (idx + 1);
    else {
      num += (idx + 1) / 2 * idx;
    }

    if(curr < x + num) {
      ++res;
      curr = d - 1 - x;
      idx = 1;
    }
    else 
      curr -= x + num;
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

