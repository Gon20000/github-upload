#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  ll n{}, k{};
  cin >> n >> k;

  vector<ll> arr(n), dp(n), highest(n);
  for(ll& x  : arr)
  cin >> x;

  sort(arr.begin(), arr.end());

  int l{}, r{};
  for(; l < n; ++l) {
    while(r < n && arr[r] - arr[l] <= k) {
      ++r;
    }

    dp[l] = r - l;
  }
  
  highest[n - 1] = dp[n - 1];
  for(int i{n - 2}; i >= 0; --i) {
    highest[i] = max(highest[i + 1], dp[i]);
  }

  int l2{}, r2{};
  ll res{};
  for(; l2 < n && r2 < n; ++l2) {
    r2 = l2 + dp[l2]
    if(r2 == n) 
      res = max(res, dp[l2]);
    else {
      res = max(res, dp[l2] + highest[r2]);
    }
  }

  cout << res << '\n';
  return 0;
}
