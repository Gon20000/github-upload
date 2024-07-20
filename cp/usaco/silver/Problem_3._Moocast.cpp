#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

vector<int> adj[201];
pair<ll, ll> cows[201];
ll radius[201];
vector<bool> visited(201, false);

ll dfs(int curr) {
  visited[curr] = true;
  ll res{1};
  for(int node : adj[curr]) {
    if(visited[node])
      continue;

    res += dfs(node);
  }

  return res;
}

void solve() {
  int n{};
  cin >> n;

  for(int i{}; i < n; ++i) {
    cin >> cows[i].first >> cows[i].second >> radius[i];
    
    // squaring it to avoid dealing with sqrt.
    radius[i] *= radius[i]; 

    for(int j{}; j < i; ++j) {
      ll dist{(cows[i].first - cows[j].first) * (cows[i].first - cows[j].first)
      + (cows[i].second - cows[j].second) * (cows[i].second - cows[j].second)};
      if(dist <= radius[j])
        adj[j].push_back(i);

      if(dist <= radius[i])
        adj[i].push_back(j);
    }
  }

  ll res{};
  for(int i{}; i < n; ++i) {
    res = max(res, dfs(i));
    visited.assign(201, false);
  }
  
  cout << res << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

