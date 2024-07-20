#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int mod{static_cast<ll>(1e9) + 7}; 
constexpr int N{1'000'001};
vector<ll> dp(N);

void solve() {
  int n{}, x{};
  cin >> n >> x;

  vector<ll> coins(n);
  for(ll& coin : coins) {
    cin >> coin;
  }
  dp[0] = 1;

  for(ll coin : coins) {
    for(ll i{coin}; i <= x; ++i) {
      dp[i] += dp[i - coin];
      dp[i] %= mod;
    }
  }

  cout << dp[x] % mod << '\n';
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
