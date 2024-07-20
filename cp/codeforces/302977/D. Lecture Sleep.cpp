#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, k{};
  cin >> n >> k;

  vector<ll> vals(n), pref1(n);
  for(int i{}; i < n; ++i) {
    cin >> vals[i];
    pref1[i] = vals[i];
    if(i > 0)
      pref1[i] += pref1[i - 1];
  }

  for(int i{}; i < n; ++i) {
    int x{};
    cin >> x;

    if(x == 0)
      vals[i] = 0;

    if(i > 0)
      vals[i] += vals[i - 1];
  }

  ll res{};
  for(int i{}; i <= n - k; ++i) {
    ll prev{}, curr{pref1[i + k - 1]}, next{vals.back() - vals[i + k - 1]};
    if(i > 0) {
      prev = vals[i - 1];
      curr -= pref1[i - 1];
    }

    res = max(res, prev + curr + next);
  }

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

