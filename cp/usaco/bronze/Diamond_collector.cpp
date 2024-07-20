#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  ll n{}, k{}, res{};
  cin >> n >> k;

  vector<ll> arr(n);
  for(ll& x  : arr)
    cin >> x;

  sort(arr.begin(), arr.end());

  ll l{}, r{};
  for(; l < n && r < n; ++l) {
    while(r < n && arr[r] - arr[l] <= k) {
      ++r;
    }

    res = max(res, r - l);
  }
  
  cout << res << '\n';
  return 0;
}
