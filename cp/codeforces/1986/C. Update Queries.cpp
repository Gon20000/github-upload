#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  string main{};
  cin >> main;

  vector<ll> cnt(n);
  for(int i{}; i < m; ++i) {
    ll x{};
    cin >> x;
    ++cnt[--x];
  }

  string sec{};
  cin >> sec;

  sort(sec.begin(), sec.end());
  int l{}, r{n - 1};
  for(int i{}; i < n; ++i) {
    if(!cnt[i])
      continue;
    r -= cnt[i] - 1;
    main[i] = sec[l++];
  }

  cout << main << '\n';
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


