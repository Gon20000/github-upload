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
  ll res{1};

  for(int i{1}; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] + arr[i - 1];
    dp[i][1] = max(abs(arr[i - 1] + dp[i - 1][0]), abs(arr[i - 1] + dp[i - 1][1]));
  }

  pair<bool, bool> p{false, false};
  ll c{max(dp[n][0], dp[n][1])};
  if(dp[n][0] == c)
    p.first = true;
  if(dp[n][1])
    p.second = true;

  for(int i{n - 1}; i >= 1; --i) {
    ll add{};
    pair<bool, bool> curr{false, false};
    if(p.first && dp[i][0] + arr[i] == dp[i + 1][0]) {
      ++add;
      curr.first = true;
    }

    if(p.second) {
      if(abs(dp[i][0] + arr[i]) == dp[i + 1][1]) {
        ++add;
        curr.first = true;
      } 

      if(abs(dp[i][1] + arr[i]) == dp[i + 1][1]) {
        ++add;
        curr.second = true;
      } 
    }

    p = curr;
    res *= add;
  }

  printf("%lld\n", res);
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


