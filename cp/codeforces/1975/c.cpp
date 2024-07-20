#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;
  
  if(n == 2) {
    cout << min(arr[0], arr[1]) << '\n';
    return;
  }

  multiset<ll> s{};
  for(int i{}; i < 3; ++i)
    s.insert(arr[i]);
  ll res{*(++s.begin())};
  for(int i{3}; i < n; ++i) {
    s.extract(arr[i - 3]);
    s.insert(arr[i]);
    res = max(res, *(++s.begin()));
  }

  res = max(res, max(min(arr[0], arr[1]), min(arr[n - 1], arr[n - 2])));
  cout << res << '\n';

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--) {
    solve();
  }

  return 0;
}

