#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll pow(ll x, ll y, ll p = 2019)
{

  // Initialize answer
  int res = 1;

  // Check till the number becomes zero
  while (y > 0) {

    // If y is odd, multiply x with result
    if (y % 2 == 1)
      res = (res * x);

    // y = y/2
    y = y >> 1;

    // Change x to x^2
    x = (x * x);
  }
  return res % p;
}

void solve() {
  string str{};
  cin >> str;

  ll n{(ll)str.size()}, res{};
  ll power{pow(10, n - 1, 2019)};
  vector<ll> dp(n);

  map<ll, ll> mp{};
  ++mp[0];

  for(int i{0}; i < n; ++i) {
    if(i > 0)
      dp[i] += dp[i - 1];

    dp[i] += (str[i] - '0') * power;
    dp[i] %= 2019;
    power = (power * 202) % 2019;
    ++mp[dp[i]];
  }

  for(auto [x, y] : mp) 
    res += (y * (y - 1)) / 2;
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



