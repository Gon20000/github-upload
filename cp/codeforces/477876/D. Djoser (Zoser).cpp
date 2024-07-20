#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;

ll high{static_cast<ll>(1e9)};
void solve() {
  ll a{}, b{}, c{}, d{};
  cin >> a >> b >> c >> d;

  ll l{0 - high}, r{high}, res{LLONG_MAX};
  while(l <= r) {
    ll mid{l + (r - l) / 2};
    ll num{(ll)pow(mid, 3ll) * a + mid * mid * b + mid * c + d};

    if(num > 0)
      r = mid - 1;
    else if(num < 0)
      l = mid + 1;
    else {
      res = mid;
      break;
    }
  }

  if(res == LLONG_MAX) {
    cout << "No\n";
    return;
  }

  cout << "Yes\n" << res << '\n';
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

