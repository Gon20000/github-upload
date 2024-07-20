#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n), dp(n);
  for(ll& x : arr)
    cin >> x;

  for(int i{}; i < n; ++i) {
    if(i > 0)
      dp[i] = max(dp[i], dp[i - 1]);
    if(i > 1)
      dp[i] = max(dp[i], dp[i - 2]);

    dp[i] += arr[i];
  }

  cout << dp[n - 1] << '\n';
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

