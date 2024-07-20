#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll check(int i, const vector<ll>& dp) {
  ll res{-2};
  if(i - 1 >= 0)
    res = max(res, dp[i - 1]);
  if(i - 3 >= 0)
    res = max(res, dp[i - 3]);
  if(i - 5 >= 0)
    res = max(res, dp[i - 5]);

  return res == -2 ? 0 : res;
}
void solve() {
  int n{};
  cin >> n;

  vector<ll> dp(n);
  for(int i{}; i < n; ++i) {
    char x{};
    cin >> x;

    if(x == 'w')
      dp[i] = -1;
    else {
      dp[i] += check(i, dp) + (x == '"');
    }
  }

  cout << dp.back() << '\n';
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

