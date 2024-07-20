#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  ll n{}, k{};
  cin >> n >> k;

  if(k & 1) {
    cout << "NO\n";
    return;
  }

  vector<ll> res(n + 1);
  for(int i{1}; i <= n; ++i)
    res[i] = i;

  ll l{1}, r{n};
  while(k > 0 && r > l) {
    while(r > l && (r - l) * 2 > k)
      --r;

    k -= (res[r] - res[l]) * 2;
    swap(res[l], res[r]);
    ++l;
    --r;
  }

  if(k != 0) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  for(int i{1}; i < n; ++i)
    cout << res[i] << ' ';
  cout << res[n] << '\n';

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

