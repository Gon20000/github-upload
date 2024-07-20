#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n{}, x{};
  cin >> n >> x;

  vector<ll> arr(n), psum(n);
  for(ll& a : arr) {
    cin >> a;
    if(a == x) {
      cout << x << '\n';
      return;
    }
  }

  sort(arr.begin(), arr.end());
  psum[0] = arr[0];
  for(size_t i{1}; i < arr.size(); ++i) {
    psum[i] += arr[i] + psum[i - 1];
  }

  // all weights are less than X
  if(psum.back() < x) {
    cout << psum.back() << '\n';
    return;
  }

  ll res{};
  for(size_t i{arr.size() - 1}; i > 0; --i) {
    if(psum[i] < x)
      break;
    
    ll diff{min(*(lower_bound(psum.begin(), psum.end(), psum[i] - x)), 
                *(lower_bound(arr.begin(), arr.end(), psum[i] - x)))};
    res = max(res, psum[i] - diff);
  }

  auto it{upper_bound(arr.begin(), arr.end(), x)};
  if(it != arr.begin()) {
    res = max(res, *(--it));
  }

  cout << res << '\n';
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
