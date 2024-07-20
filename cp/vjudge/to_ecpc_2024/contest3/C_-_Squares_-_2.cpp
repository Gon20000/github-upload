#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  vector<ld> dp(101);
  dp[0] = 50;

  int n{};
  cin >> n;
  for(int i{1}; i < n; ++i) {
    dp[i] = dp[i - 1] + 50 / pow(4, i);
  }

  cout << setprecision(6) << dp[n - 1] << '\n';
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

