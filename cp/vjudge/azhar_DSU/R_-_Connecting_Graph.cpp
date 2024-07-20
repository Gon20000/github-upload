#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;


class DSU {
  vector<int> m_p{}, m_size{};
  vector<map<int, int>> m_children{};

public:
  DSU(int size) : m_p(size), m_size(size, 1), m_children(size) {
    for(int i{}; i < size; ++i) {
      m_p[i] = i;
      m_children[i][i] = 0;
    }
  }

  int get(int x) {
    return (m_p[x] == x ? x : get(m_p[x]));
  }

  void unify(int x, int y, int q) {
    int x_root{get(x)}, y_root{get(y)};

    if(x_root == y_root)
      return;

    if(m_size[x_root] < m_size[y_root])
      swap(x_root, y_root);

    m_p[y_root] = x_root;
    m_size[x_root] += m_size[y_root];
    for(auto [a, b] : m_children[y_root]) {
      m_children[x_root][a] = q;
    }
  }

  ll getRes(int u, int v) {
    ll res{m_children[u].count(v) ? m_children[u][v] : -1};

    while(m_p[u] != u && res == -1) {
      u = m_p[u];
      if(m_children[u].count(v))
        res = m_children[u][v];
    }

    return res;
  }

};

void solve() {
  int n{}, m{};
  cin >> n >> m;

  DSU dsu{n};

  for(int i{1}; i <= m; ++i) {
    int t{}, x{}, y{};
    cin >> t >> x >> y;

    if(t == 1)
      dsu.unify(--x, --y, i);
    else
      cout << dsu.getRes(--x, --y) << '\n';
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

