#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n), res(n);
  for(ll& x : arr)
    cin >> x;

  int l{}, r{n - 1};
  
  for(int i{}; i < n; ++i) {
    if(i % 2 == 0)  {
      res[l] = arr[i];
      ++l;
    }
    else {
      res[r] = arr[i];
      --r;
    }
  }

  for(int i{}; i < n - 1; ++i)
    cout << res[i] << ' ';

  cout << res[n - 1] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  // cin >> t;

  while(t--)
    solve();

  return 0;
}
