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

  ll l{}, r{};

  for(int i{}; i < n - 1; ++i) {
    l += arr[i];
    r = abs(r + arr[i]);
  }

    printf("%lld\n", max(max(arr.back() + l, abs(arr.back() + l), abs(arr.back() + r)));
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

