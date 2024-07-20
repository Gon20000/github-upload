#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  ll ans{LLONG_MAX};

  for(ll i{0}; i < (1 << n); ++i) {
    ll curr1{}, curr2{};
    
    for(int j{0}; j < n; ++j) {
      if((i & (1 << j)) != 0) {
        curr1 |= arr[j];
      } 
      else {
        curr2 |= arr[j];
      }
    }
    ans = min(ans, abs(curr2 - curr1));
  }

  cout << ans  << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while(t--)
    solve();

  return 0;
}
