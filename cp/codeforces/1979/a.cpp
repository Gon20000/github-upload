#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  ll res{LLONG_MAX};
  for(int i{}; i < n - 1; ++i) {
    res = min(max(arr[i], arr[i + 1]) - 1, res);
  } 

  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;

  while(t--)
    solve();

  return 0;
}
