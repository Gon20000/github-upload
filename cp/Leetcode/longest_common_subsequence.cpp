#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  string str1{}, str2{};
  cin >> str1 >> str2;
  
  int n{(int)str1.size()}, m{(int)str2.size()};

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for(int i{1}; i <= n; ++i) {
    for(int j{1}; j <= m; ++j) {
      if(str1[i - 1] == str2[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  cout << dp[n][m] << '\n';
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

