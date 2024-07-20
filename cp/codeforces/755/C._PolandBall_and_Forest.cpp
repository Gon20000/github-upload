#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void dfs(int curr, const vector<vector<int>>& adj, bitset<10001>& visited) {
  visited[curr] = true;
  for(int node : adj[curr]) {
    if(visited[node])
      continue;
    dfs(node, adj, visited);
  }
}

void solve() {
  int n{};
  cin >> n;
  
  vector<vector<int>> adj(n + 1);
  bitset<10001> visited{};

  for(int i{1}; i <= n; ++i) {
    ll x{};
    cin >> x;

    adj[x].push_back(i);
    adj[i].push_back(x);
  }

  int res{};
  for(int i{1}; i <= n; ++i) {
    if(visited[i])
      continue;

    ++res;
    dfs(i, adj, visited);
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

