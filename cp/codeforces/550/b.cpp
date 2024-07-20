#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n{}, l{}, r{}, x{};
  cin >> n >> l >> r >> x;

  vector<ll> arr(n);
  for(ll& x : arr) 
    cin >> x;

  ll subsets{1 << n}, res{};
  for(ll i{3}; i < subsets; ++i) {
    ll first{INT_MAX}, last{INT_MIN}, total{};

    for(int j{}; j < n; ++j) {
      if((i >> j) & 1) {
        first = min(first, arr[j]);
        last = max(last, arr[j]);
        total += arr[j];
      }
    }
  
    // cout << total  << ' ' << first << ' ' << last << '\n';
    if(total >= l && total <= r && last - first >= x)
      ++res;
  }

  cout << res << '\n';
  return 0;
}
