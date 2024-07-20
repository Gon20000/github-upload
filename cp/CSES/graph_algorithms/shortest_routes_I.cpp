#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using route_t = pair<ll, ll>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, m{};
  cin >> n >> m;

  vector<vector<route_t>> adj(n + 1);
  vector<bool> visited(n + 1, false);
  vector<ll> dist(n + 1, LLONG_MAX);
  dist[1] = 0;

  while(m--) {
    int x{}, y{};
    ll l{};
    cin >> x >> y >> l;
    adj[x].push_back({y, l});
  }

  priority_queue<route_t, vector<route_t>, greater<route_t>> heap{};
  heap.push({0, 1});

  while(!heap.empty()) {
    route_t curr {heap.top()};
    heap.pop();

    if(visited[curr.second])
      continue;
    visited[curr.second] = true;

    for(route_t pair : adj[curr.second]) {
      int city{pair.first};
      ll l{pair.second};

      if(visited[city])
        continue;

      if (dist[curr.second] + l < dist[city]) {
        dist[city] = dist[curr.second] + l;
        heap.push({dist[city], city});
      }
    }
  }

  for (int i{1}; i < n; ++i) {
    cout << dist[i] << ' ';
  }
  cout << dist[n] << '\n';

  return 0;
}
