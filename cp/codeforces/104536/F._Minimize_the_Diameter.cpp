#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using res_t = pair<ll, int>;

bitset<200001> visited{};
res_t bfs(int start, const vector<vector<int>>& adj) {
  queue<res_t> q{};
  q.push({0, start});

  res_t res{};
  while(!q.empty()) {
    res_t p = q.front();
    q.pop();
    visited[p.second] = true;

    res = max(res, p);
    for(int node : adj[p.second]) {
      if(!visited[node])
        q.push({p.first + 1, node});
    }
  }
  visited.reset();

  return res;
}

void solve() {
  int n{};
  cin >> n;

  vector<vector<int>> adj1(n);
  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;
    --x; --y;
    adj1[x].push_back(y);
    adj1[y].push_back(x);
  }

  int m{};
  cin >> m;

  vector<vector<int>> adj2(m);
  for(int i{}; i < m - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;
    --x; --y;
    adj2[x].push_back(y);
    adj2[y].push_back(x);
  }

  int temp1{bfs(0, adj1).second}, temp2{bfs(0, adj2).second};
  ll dist1{bfs(temp1, adj1).first}, dist2{bfs(temp2, adj2).first};

  cout << max({dist1, dist2, ((dist1 + 1) / 2 + (dist2 + 1) / 2) + 1}) << '\n';
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

