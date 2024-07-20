#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll max_n{(ll)1e5 + 1};
vector<vector<ll>> adj(max_n);
bool vis[max_n];

ll dfs(ll curr, const vector<ll>& a) {
  if(vis[curr])
    return 0;

  vis[curr] = true;
  ll res{a[curr]};
  for(ll& node : adj[curr]) {
    if (vis[node])
      continue;

    res += dfs(node, a);
  }

  return res;
}

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<ll> a(n);
  for(ll& x : a)
  cin >> x;

  for(int i{}; i < m; ++i) {
    ll x{}, y{};
    cin >> x >> y;

    --x;
    --y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  ll ans{};
  for(int i{}; i < n; ++i) {
    if(!vis[i]) {
      ans = max(ans, dfs(i, a));
    }
  }

  cout << ans << '\n';
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
