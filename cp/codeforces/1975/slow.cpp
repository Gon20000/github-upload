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

  for(int i{0}; i < n; ++i) {
    for(int j{i + 1}; j < n; ++j) {
      bool ans{true};

      for(int k{}; k < n && ans; ++k) {
        if(arr[k] % arr[i] != 0 && arr[k] % arr[j] != 0)
          ans = false;
      }

      if(ans)
        cout << "YES\n";
    }
  }

  cout << "NO\n";
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
