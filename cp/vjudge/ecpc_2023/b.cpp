#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool prime(ll x) {
  if(x <= 1)
    return false;

  for(ll i{2}; i * i <= x; ++i) {
    if(x % i == 0)
      return false;
  }

  return true;
}

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  ll res{};
  for(int i{}; i < n; ++i) {
    for(int j{i + 1}; j < n; ++j) {
      if(prime(arr[i] + arr[j])) {
        res += 2;
      }
    }
  }

  cout << res << '\n';
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

