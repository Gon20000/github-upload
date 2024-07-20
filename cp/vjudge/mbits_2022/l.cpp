#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr)
  cin >> x;

  for(int i{}; i < n; ++i) {
    ll res{}, l{i}, r{i};

    while(l != -1 && r != -1) {
      auto low{--lower_bound(arr.begin(), arr.end(), arr[i])};
     if(i > 0)
        prev = arr[i - 1];
      if(i < n - 1)
        nex = arr[i + 1];

      if(arr[i] - prev <= abs(arr[i] - nex)) {
        cout << arr[i] + arr.back() - 2 * arr.front();
      }
      else 
      cout << 0 - arr[i] - arr.front() + 2 * arr.back();

      cout << '\n';
    }
  }
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
