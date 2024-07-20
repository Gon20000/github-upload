#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr) {
    cin >> x;
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(2));

  for(int i{1}; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] + arr[i - 1];
    dp[i][1] = max(abs(arr[i - 1] + dp[i - 1][0]), abs(arr[i - 1] + dp[i - 1][1]));
  }

  cout << max(dp[n][0], dp[n][1]) << '\n';
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


