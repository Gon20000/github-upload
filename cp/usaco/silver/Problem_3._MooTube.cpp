#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using tv_t = vector<vector<pair<ll, ll>>>;

ll dfs(ll curr, ll prev, ll rel, const ll k, const tv_t& adj) {
  if(rel < k)
    return 0;
  ll res{rel >= k && rel != LLONG_MAX};

  for(auto [node, r] : adj[curr]) {
    if(node == prev)
      continue;
    
    res += dfs(node, curr, min(rel, r), k, adj);
  }
  return res;
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  tv_t adj(n + 1);
  for (size_t i = 0; i < n - 1; i++) {
    ll x{}, y{}, r{};
    cin >> x >> y >> r;

    adj[x].push_back({y, r});
    adj[y].push_back({x, r});
  }

  while(q--) {
    ll x{}, y{};
    cin >> x >> y;

    cout << dfs(y, -1, LLONG_MAX, x, adj) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

