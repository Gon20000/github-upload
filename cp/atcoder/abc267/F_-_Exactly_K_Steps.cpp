#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;

constexpr int LOG{18}, N{200'001};
vector<int> adj[N];
ll depth[N];

sparse_t sparse1(LOG, vector<ll>(N, -1)), sparse2(LOG, vector<ll>(N, -1));

pair<ll, ll> dfs2(int curr, int prev, int depth) {
  pair<ll, ll> pcurr = {curr, depth};
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    pair<ll, ll> pnode {dfs2(node, curr, depth + 1)};
    if(pnode.second > pcurr.second)
      pcurr = pnode;
  }

  return pcurr;
}

void dfs(int curr, int prev, bool first = true) {
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    if(first)
      sparse1[0][node] = curr;
    else
      sparse2[0][node] = curr;
    
    dfs(node, curr, first);
  }
}

void initSparse(int n) {
  for(int i{1}; i < LOG; ++i) {
    for(int j{0}; j < n; ++j) {
      ll tmp{sparse1[i - 1][j]}, tmp2{sparse2[i - 1][j]};

      if(tmp != -1)
        sparse1[i][j] = sparse1[i - 1][tmp];

      if(tmp2 != -1)
        sparse2[i][j] = sparse2[i - 1][tmp2];
    }
  }
}

ll kth_step(int u, int k) {
  ll first{u}, second{u};

  for(int i{}; i < LOG; ++i, k >>= 1) {
    if((k & 1) == 0)
      continue;

    if(first != -1)
      first = sparse1[i][first];

    if(second != -1)
      second = sparse2[i][second];

  }

  return max(first, second) + 1;
}

void solve() {
  int n{};
  cin >> n;

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  // starting at an endpoint of the diameter guarantees that we will
  // include all nodes and highest depth
  ll start{dfs2(0, -1, 0).first};
  ll end{dfs2(start, -1, 0).first};
  dfs(start, -1);
  dfs(end, -1, false);

  initSparse(n);

  int q{};
  cin >> q;

  while(q--) {
    int u{}, k{};
    cin >> u >> k;

    ll res{kth_step(--u, k)};
    cout << (res == 0 ? -1 : res) << '\n';
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

