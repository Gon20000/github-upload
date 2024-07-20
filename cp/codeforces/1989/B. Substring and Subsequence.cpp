#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ll lcs(string& text1, string& text2) {

  vector<vector<ll>> dp(text1.size(), vector<ll>(2));
  dp[0][0] = text1[0] == text2[0];

  for (int i{1}; i < text1.size(); ++i) {
    dp[i][1] = dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    if (dp[i][0] < text2.size() && text1[i] == text2[dp[i][0]])
      ++dp[i][0];
  }

  return max(dp[text1.size() - 1][0], dp[text1.size() - 1][1]);
}

void solve() {
  string a{}, b{};
  cin >> a >> b;

  ll cnt{};
  for(int i{}; i < b.size(); ++i) {
      string c{b.substr(i, b.size())};
    cnt = max(cnt, 
              lcs(a, c));
  }

  int x{int(a.size() + b.size())};
  cout << x - cnt << '\n';
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

