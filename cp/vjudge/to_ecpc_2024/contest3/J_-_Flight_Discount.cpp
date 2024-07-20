#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using route_t = pair<ll, ll>;
using used_t = pair<route_t, bool>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, m{};
  cin >> n >> m;
  vector<vector<route_t>> adj(n + 1);
  vector<route_t> prev(n + 1);
  vector<ll> dist(n + 1, LLONG_MAX);
  vector<bool> visited(n + 1);

  priority_queue<used_t, vector<used_t>, greater<used_t>> q{};
  while(m--) {
    ll x{}, y{}, w{};
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
  }

  q.push({{0, 1}, false});
  while(!q.empty()) {
    auto [route, done] = q.top();
    auto [cdist, node] = route;
    q.pop();
    visited[node] = true;

    if(cdist < dist[node])
      dist[node] = cdist;
    for(route_t& p : adj[node]) {
      if(visited[p.first])
        continue;

      q.push({{cdist + p.second, p.first}, done});
      if(!done)
        q.push({{cdist + p.second / 2, p.first}, true});
    }
  }

  cout << dist[n] << '\n';

  return 0;
}

