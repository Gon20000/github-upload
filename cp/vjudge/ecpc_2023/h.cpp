#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> dp(n);
  for(int i{}; i < n; ++i) {
    ll x{};
    cin >> x;

    dp[i] = x;
  }

  sort(dp.begin(), dp.end());

  ll curr{};
  for(ll i{}; i < n; ++i) {
    if(curr < dp[i]) {
      break;
    }
    
    ++curr;
  }

  cout << curr << '\n';
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
