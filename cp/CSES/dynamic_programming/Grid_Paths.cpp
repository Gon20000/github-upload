#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll mod{static_cast<ll>(1e9) + 7};
void solve() {
  int n{};
  cin >> n;
  vector<bitset<1000>> check(n);
  vector<vector<ll>> dp(n, vector<ll>(n));
  ++dp[0][0];

  for(int i{}; i < n; ++i) {
    for(int j{}; j < n; ++j) {
      char x{};
      cin >> x;
      check[i][j] = (x == '.');

      if(j > 0 && check[i][j - 1])
        dp[i][j] += dp[i][j - 1];
      if(i > 0 && check[i - 1][j])
        dp[i][j] += dp[i - 1][j];

      dp[i][j] %= mod;
    }
  }

  cout << (check[n - 1][n - 1] ? dp[n - 1][n - 1] : 0) << '\n';
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

