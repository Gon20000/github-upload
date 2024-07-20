#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, q{};
  cin >> n >> q;

  vector<ll> arr(n);
  vector<ll> near(n);
  for(ll& x : arr)
    cin >> x;

  sort(arr.begin(), arr.end());
  near[0] = arr[0] - 1;
  for(int i{1}; i < n; ++i) {
    near[i] = near[i - 1] + arr[i] - arr[i - 1] - 1;
  }

  near.push_back(LLONG_MAX);
  while(q--) {
    ll x{};
    cin >> x;

    auto it{lower_bound(near.begin(), near.end(), x)};
    if(it == near.begin()) {
      cout << x << '\n';
      continue;
    }

    --it;
    ll dist{distance(near.begin(), it)};
    cout << arr[dist] + x - near[dist] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

