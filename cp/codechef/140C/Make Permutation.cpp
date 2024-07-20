#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<bool> check(n + 1);
  vector<ll> arr(n);
  for(ll& x : arr) {
    cin >> x;

    ll i{x};
    while(check[i])
      ++i;
    if(i < check.size())
      check[i] = true;
  }

  for(int i{1}; i <= n; ++i) {
    if(!check[i]) {
      cout << "NO\n";
      return;
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

