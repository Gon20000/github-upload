#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool test(int i, ll curr, vector<vector<ll>>& dp) {
  if(i >= dp.size() - 1)
    return true;

  if(curr > dp[i][0])
    return false;

  return test(i + 1, dp[i][0], dp);
}

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
  cin >> x;

  vector<vector<ll>> dp(n, vector<ll>(2));

  for(int i{}; i < n - 1; ++i) {
    dp[i][0] = gcd(arr[i], arr[i + 1]);

    if(i < n - 2) {
      dp[i][1] = gcd(arr[i], arr[i + 2]);
      if(i > 0 && dp[i][1] < dp[i - 1][0])
        dp[i][1] = LLONG_MAX;
    }
  } 

  ll curr{dp[0][0]};
  bool done{false};

  for(int i{1}; i < n - 1; ++i) {

    if(curr > dp[i][0]) {
      if(done) {
        cout << "NO\n";
        return;
      }
      else {
        bool res{false};

        if(i < 2 || (i > 1 && dp[i - 2][0] <= dp[i - 1][1])) {
          res |= test(i + 1, dp[i - 1][1], dp);
        }

        if(i < 2) 
          res |= test(i + 1, dp[i][0], dp);

        if(dp[i][1] != LLONG_MAX && dp[i][1] >= curr) {
          res |= test(i + 2, dp[i][1], dp);
        }

        if(i > 1)
          res |= test(i, dp[i - 2][1], dp);

        if(res) 
          cout << "YES\n";
        else {
          cout << "NO\n";
        }
        return;
      }
    }
    else {
      curr = dp[i][0];
    }
  }

  cout << "YES\n";
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

