#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void dfs(int curr, vector<vector<ll>>& adj, bitset<200001>& visited, vector<ll>& res) {
  visited[curr] = true;
  if(adj[curr].empty()) {
  }
  
  for(ll node : adj[curr]) {
    if(visited[node])
      continue;
    dfs(node, adj, visited, res);
  }

  res.push_back(curr);
}

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n);
  pair<ll, ll> high{INT_MAX, LLONG_MAX};
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
    if(arr[i] < high.second)
      high = {i + 1, arr[i]};
  }

  vector<vector<ll>> adj(n + 1);
  bitset<200001> visited{};

  for(int i{1}; i < n; ++i) {
    ll x{}, y{};
    cin >> x >> y;

    adj[y].push_back(x);
    adj[x].push_back(y);
  }

  vector<ll> res{};
  dfs(high.first, adj, visited, res);
  cout << res.size() - 1 << '\n';
  for(int i{}; i < res.size() - 1; ++i)
    if(res[i] != high.first)
      cout << res[i] << ' ';
  if(res.back() != high.first)
    cout << res.back();
  cout << '\n';
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

