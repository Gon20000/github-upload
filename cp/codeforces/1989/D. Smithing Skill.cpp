#include <bits/stdc++.h>
using namespace std

using ll = long long;
using ld = long double;

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<ll> a(n), b(n);
  for(ll& x : a)
    cin >> x;
  for(ll& x : b)
    cin >> x;

  map<ll, pair<ll, ll>> mp{};
  for(int i{}; i < n; ++i) {
    if(mp.count(a[i] - b[i]) == 0) {
      mp[a[i] - b[i]] = {a[i], b[i]};
      continue;
    }

    if(a[i] < mp[a[i] - b[i]].first)
      mp[a[i] - b[i]] = {a[i], b[i]};
  }

  priority_queue<ll> q{};
  for(int i{}; i < m; ++i) {
    ll x{};
    cin >> x;
    q.push(x);
  }

  ll res{};
  for(auto [diff, p] : mp) {
    while(q.top() >= p.first) {
      ll c{q.top()};
      q.pop();

      ll cnt{(c - p.first) / diff};
      c -= diff * cnt;
      if(c >= p.first) {
        ++cnt;
        c -= diff;
      }

      res += cnt * 2; 
      q.push(c);
    }
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

