#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;
  vector<ll> arr(n);

  for(ll& x : arr)
    cin >> x;
  sort(arr.begin(), arr.end());

  while(k > 0 && !arr.empty()) {
    arr.pop_back();;
    --k;
  }
  ll res{};
  for(int i{}; i < arr.size(); ++i)
    res += arr[i];

  cout << res << '\n';
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

