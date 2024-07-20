#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  ll n{}, x{};
  cin >> n >> x;

  vector<ll> arr(n);
  for(ll& a : arr)
  cin >> a;

  sort(arr.begin(), arr.end(), std::less<ll>());
  ll res{0};
  ll curr{}, r{1}, l{};
  while(l < n) {
    curr += arr[l];
    while(r < n && arr[r] - arr[r - 1] <= x) {
      curr += arr[r];
      ++r;
    }

    res = max(res, curr);
    curr = 0;
    l = r;
    ++r;
  }

  cout << res << '\n';
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
