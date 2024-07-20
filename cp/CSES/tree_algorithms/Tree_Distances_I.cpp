#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int max_n{200'001};
vector<int> adj[max_n];
// dist from a to nodes, dist from b to nodes as diameter is the longest path :exploding_head:
int dist[max_n], dist2[max_n];
bitset<max_n> visited{};

int bfs(int node, bool check1 = false, bool check2 = false) {
  queue<pair<int, int>> q{};
  q.push({node, 0});

  pair<int, int> res{};
  while(!q.empty()) {
    pair<int, int> p(q.front());
    q.pop();
    visited[p.first] = true;

    if(p.second > res.second)
      res = p;

    for(int node : adj[p.first]) {
      if(visited[node])
        continue;

      if(check1)
        dist[node] = p.second + 1;
      if(check2)
        dist2[node] = p.second + 1;

      q.push({node, p.second + 1});
    }
  }

  visited.reset();
  return res.first;
}

void solve() {
  int n{};
  cin >> n;

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int end1{bfs(1)};
  // calculate distances from node a
  int end2{bfs(end1, true, false)};

  // calculate distances from node b
  int end3{bfs(end2, false, true)};

  for(int i{1}; i < n; ++i) {
    cout << max(dist[i], dist2[i]) << ' ';
  }
  cout << max(dist[n], dist2[n]) << '\n';
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

