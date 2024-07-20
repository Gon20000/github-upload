#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  ll curr{};
  for(ll& x : arr) {
    cin >> x;
    curr = max(curr, x);
  }

  for(ll x : arr) {
    curr &= x;
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

