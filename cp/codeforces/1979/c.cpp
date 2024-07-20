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

  ll l{}, r{ll(1e9)}, res{-1};

  while(l <= r) {
    ll mid{l + (r - l) / 2}, total{};

    vector<ll> arr2(n);
    for(int i{}; i < n; ++i) {
      arr2[i] = mid / arr[i] + 1;
      total += arr2[i];
    }

    bool check{true};
    for(int i{}; i < n; ++i) {
      if(arr2[i] * arr[i] <= total) {
        check = false;
        break;
      }
    }

    if(check) {
      for(int i{}; i < n - 1; ++i)
        cout << arr2[i] << ' ';
      cout << arr2[n - 1] << '\n';
      res = 1;
      break;
    }
    else {
      r = mid - 1;
    }
  }

  if(res == -1)
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

