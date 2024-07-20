#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  for(ll& x : arr) {
    cin >> x;
  }

  sort(arr.begin(), arr.end());

  int i{1};
  while(i < n && arr[i] % arr[0] == 0)
    ++i;

  int k{i};
  for(; i < n; ++i) {
    if(arr[i] % arr[0] != 0 && arr[i] % arr[k] != 0) {
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

  while(t--) {
    solve();
  }

  return 0;
}
