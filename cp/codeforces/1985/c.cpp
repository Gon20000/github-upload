#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  ll sum{}, res{}, high{};
  for(int i{0}; i < n; ++i) {
    high = max(high, arr[i]);
    sum += arr[i];
    if(sum - high == high)
      ++res;
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

