#include <bits/stdc++.h>
using namespace std;

int n{}, p{};
// dp[price][items taken (to avoid dups)]
int dp[100001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> p;

  vector<int> prices(n), pages(n);
  for(int& x : prices)
  cin >> x;
  for(int& x : pages)
  cin >> x;

  for(int i{}; i <= p; ++i) {
    for(int j{}; j < n; ++j) {
      if(i + prices[j] > p)
        continue;
      
      if(j > 0)
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);

      dp[i + prices[j]][j + 1] = max(dp[i + prices[j]][j + 1], dp[i][j] + pages[j]);
    }
  }

  cout << max(dp[p][n - 1], dp[p][n]) << '\n';

  return 0;
}
