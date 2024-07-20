#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
public:
  vector<int> m_p{}, m_size{};
  DSU(int n) : m_p(n), m_size(n, 1) {
    for(int i{}; i < n; ++i)
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

    m_size[x_root] += m_size[y_root];
    m_p[y_root] = x_root;
  }

  void getRes() {
    set<pair<int, int>> s{};
    for(int i{}; i < m_p.size(); ++i) {
      int x{get(i)};
      s.insert({m_size[x], x});
    }

    if(s.size() < 2)
      return;

    auto it{--s.end()};
    auto it2{prev(it)};
    unify(it->second, it2->second);
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{};
  cin >> n;

  DSU dsu{n};
  for(int i{}; i < n; ++i) {
    int x{};
    cin >> x;

    dsu.unify(i, --x);
  }

  dsu.getRes();
  vector<bool> visited(n);
  ll res{};
  for(int i{}; i < n; ++i) {
    int curr{dsu.get(i)};
    if(visited[curr])
      continue;

    res += pow(dsu.m_size[curr], 2);
    visited[curr] = true;
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

