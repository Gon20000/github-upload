#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n{};
  cin >> n;

  vector<ll> ori(n), found(n);
  for(ll& x : ori)
  cin >> x;
  for(ll& x : found)
  cin >> x;

  int m{};
  cin >> m;

  map<ll, vector<ll>> mp{};
  for(int i{}; i < m; ++i) {
    ll x{};
    cin >> x;

    mp[x].push_back(i);
  }

  ll idx{-1};
  for(int i{}; i < n; ++i) {
    if(ori[i] != found[i]) {
      if(mp[found[i]].empty()) {
        cout << "NO\n";
        return;
      }
      else {
        idx = max(idx, mp[found[i]].back());
        mp[found[i]].pop_back();
      }
    }
    else {
      if(!mp[found[i]].empty())
        idx = max(idx, mp[found[i]].back());
    }
  }

  for(auto& [x, y] : mp) {
    if(y.empty())
      continue;

    if(y.back() > idx) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  return;
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

