#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;


class DSU {
  // diameters of every parent
  vector<ll> m_diam{};

public:
  vector<int> m_p{}, m_size{};
  DSU(int size) : m_p(size), m_size(size, 1), m_diam(size) {
    for(int i{}; i < size; ++i)
      m_p[i] = i;
  }

  int get(int x) {
    return m_p[x] = (m_p[x] == x ? x : get(m_p[x]));
  }

  void unify(int x, int y) {
    int x_root{get(x)}, y_root{get(y)};

    if(x_root == y_root)
      return;

    if(m_size[x_root] < m_size[y_root])
      swap(x_root, y_root);

    // minimum diameter after merging is usually distance from both centers + 1
    // but in case of adding a small tree to a large 1, it's the large one
    ll val{(m_diam[x_root] + 1) / 2 + (m_diam[y_root] + 1) / 2 + 1};
    m_diam[x_root] = max({m_diam[x_root], m_diam[y_root], val});

    m_p[y_root] = x_root;
    m_size[x_root] += m_size[y_root];
  }

  void initTree(int node, int diam) {
    node = get(node);
    m_diam[node] = diam;
  }

  ll getRes(int x) {
    return m_diam[get(x)];
  }

};

vector<int> adj[300'001];

pair<int, int> dfs(int curr, int prev, int depth = 0) {
  pair<int, int> res{curr, depth};
  
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    pair<int, int> next{dfs(node, curr, depth + 1)};
    if(next.second > res.second)
      res = next;
  }

  return res;
}

void solve() {
  int n{}, m{}, q{};
  cin >> n >> m >> q;

  DSU dsu{n};
  while(m--) {
    int a{}, b{};
    cin >> a >> b;

    adj[--a].push_back(--b);
    adj[b].push_back(a);
    dsu.unify(a, b);
  }

  for(int i{}; i < n; ++i) {
    if(dsu.m_size[i] == 1 || dsu.m_p[i] != i)
      continue;

    int first{dfs(i, -1).first};
    int diameter{dfs(first, -1).second};
    dsu.initTree(first, diameter);
  }

  while(q--) {
    int t{}, x{}, y{};
    cin >> t;

    if(t == 1) {
      cin >> x;
      cout << dsu.getRes(--x) << '\n';
    }
    else {
      cin >> x >> y;
      dsu.unify(--x, --y);
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}

