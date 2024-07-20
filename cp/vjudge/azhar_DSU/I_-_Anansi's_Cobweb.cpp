#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
  vector<int> m_p{}, m_size{};
  int cnt{};

public:
  DSU(int n) : m_p(n), m_size(n, 1), cnt{n} {
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
    --cnt;
  }

  int getRes() {
    return cnt;
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{}, m{}, q{};
  cin >> n >> m;

  DSU dsu{n};
  vector<pair<int, int>> edges(m);
  for(auto& x : edges) {
    cin >> x.first >> x.second;
    --x.first; --x.second;
  }

  cin >> q;
  bitset<100000> rem{};

  vector<int> queries(q);
  for(int& x : queries) {
    cin >> x;
    rem[--x] = true;
  }

  for(int i{}; i < m; ++i) {
    if(!rem[i])
      dsu.unify(edges[i].first, edges[i].second);
  }

  vector<int> res(q);
  for(int i{q - 1}; i >= 0; --i) {
    res[i] = dsu.getRes();
    dsu.unify(edges[queries[i]].first, edges[queries[i]].second);
  }

  for(int i{}; i < q - 1; ++i) 
    cout << res[i] << ' ';
  cout << res.back() << '\n';
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

