#include <bits/stdc++.h>
using namespace std;

constexpr size_t max_val{1000 * 100  + 1};
// the value represents the minimum index taken to form this number
int dp[max_val];

void setElement(int idx, int val) {
  if(!dp[idx])
    dp[idx] = val;
  else {
    dp[idx] = min(dp[idx], val);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{};
  cin >> n;

  vector<int> prices(n), res{};

  for(int i{}; i < n; ++i) {
    cin >> prices[i];

    setElement(prices[i], i + 1);
  }

  for(int i{1}; i < max_val; ++i) {
    if (!dp[i])
      continue;

    res.push_back(i);
    for(int j{dp[i]}; j < n; ++j) {
      if(i + prices[j] < max_val)
        setElement(i + prices[j], j + 1);
    }
  }

  cout << res.size() << '\n';
  for(int i{}; i < res.size() - 1; ++i) {
    cout << res[i] << ' ';
  }
  cout << res[res.size() - 1] << '\n';

  return 0;
}
