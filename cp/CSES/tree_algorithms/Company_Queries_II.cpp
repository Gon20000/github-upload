#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;

constexpr int N{200'001}, LOG{18};
vector<int> adj[N];
int depth[N];

void dfs(int curr, int prev, int dep = 0) {
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    dfs(node, curr, dep + 1);
  }

  depth[curr] = dep;
}

ll k_step(int node, int steps, const sparse_t& sparse) {
  for(int i{}; i < LOG; ++i) {
    if(steps & 1)
      node = sparse[i][node];
    steps >>= 1;
  }
  
  return node;
}

ll lca(int x, int y, const sparse_t& sparse) {
  if(depth[x] > depth[y])
    swap(y, x);

  if(depth[x] != depth[y]) 
    y = k_step(y, depth[y] - depth[x], sparse);

  if(x == y)
    return x;

  for(int i{LOG - 1}; i >= 0; --i) {
    if(sparse[i][x] == sparse[i][y])
      continue;
    
    x = sparse[i][x];
    y = sparse[i][y];
  }

  return sparse[0][x];
}
  
void solve() {
  int n{}, q{};
  cin >> n >> q;

  sparse_t sparse(LOG, vector<ll>(n, -1));
  for(int i{1}; i < n; ++i) {
    int x{};
    cin >> x;

    adj[--x].push_back(i);
    adj[i].push_back(x);
    sparse[0][i] = x;
  }

  dfs(0, -1);

  for(int i{1}; i < LOG; ++i) {
    for(int j{1}; j < n; ++j) {
      if(sparse[i - 1][j] == -1)
        continue;

      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  while(q--) {
    int x{}, y{};
    cin >> x >> y;

    cout << lca(--x, --y, sparse) + 1 << '\n';
  }
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

