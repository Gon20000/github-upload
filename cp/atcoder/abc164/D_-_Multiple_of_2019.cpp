#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string str{};
  cin >> str;

  ll n{(ll)str.size()}, res{};
  vector<ll> powers(n + 1);
  powers[0] = 1;

  for(int i{1}; i <= n; ++i)
    powers[i] = (powers[i - 1] * 10) % 2019;
  vector<ll> dp(n);

  map<ll, ll> mp{};
  ++mp[0];

  for(int i{0}; i < n; ++i) {
    if(i > 0)
      dp[i] += dp[i - 1] * 10;

    dp[i] += (str[i] - '0');
    dp[i] %= 2019;
    ll x{(dp[i] * powers[n - i]) % 2019};
    res += mp[x];
    ++mp[x];
  }

  cout << res << '\n';
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


