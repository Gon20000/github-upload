#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int D{1 << 3};

void solve() {
  int n{};
  cin >> n;

  vector<vector<ll>> dp(n, vector<ll>(D, (ll)1e15));

  for(int i{}; i < n; ++i) {
    ll cost{}, mask{};
    string str{};
    cin >> cost >> str;

    for(char chr : str) {
      mask |= (1 << (chr - 'A'));
    }

    dp[i][mask] = min(dp[i][mask], cost);

    for(int j{D - 1}; j >= 0 && i > 0; --j) { dp[i][mask | j] = min(dp[i][mask | j], dp[i - 1][j] + cost);
    }

    for(int j{}; j < D && i < n - 1; ++j) {
      dp[i + 1][j] = dp[i][j];
    }
  }

  cout << (dp[n - 1][7] == (ll)1e15 ? -1 : dp[n - 1][7]) << '\n'; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

