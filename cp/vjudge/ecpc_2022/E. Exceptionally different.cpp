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

  vector<ll> mp(1048576, 0), mults(21, 1);
  for(int i{1}; i < 21; ++i)
    mults[i] = mults[i - 1] * 2;
  ++mp[arr[0]];

  ll res{};
  for(int i{1}; i < n; ++i) {
    for(int j{i + 1}; j < n; ++j) {
      for(int x{1}; x < 20; ++x) {
        ll num{arr[i] ^ arr[j] ^ mults[x]};
        res += mp[num];
      }
    }
    ++mp[arr[i]];
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

