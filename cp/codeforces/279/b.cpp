#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n{}, t{};
  cin >> n >> t;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  ll r{}, curr{}, res{};
  for(int l{}; l < n  && r < n; ++l) {
    while(r < n && curr + arr[r] <= t) {
      curr += arr[r];
      ++r;
    }
    
    res = max(res, r - l);
    curr -= arr[l];
  }

  cout << res << '\n';
  return 0;
}
