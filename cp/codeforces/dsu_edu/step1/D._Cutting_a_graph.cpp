#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
  vector<int> m_p{}, m_size{};

public:
  DSU(int n) : m_p(n), m_size(n) {
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

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{}, m{}, k{};
  cin >> n >> m >> k;

  vector<string> res{};
  while(m--) {
    int x{}, y{};
    cin >> x >> y;
    --x; --y;

    /*adj[x].push_back(y);*/
    /*adj[y].push_back(x);*/
  }

  DSU dsu(n);
  vector<tuple<bool, int, int>> queries(k);
  for(int i{}; i < k; ++i) {
    string str{};
    int x{}, y{};
    cin >> str >> x >> y;
    
    queries[i] = make_tuple(str[0] == 'a', --x, --y);
  }

  while(k--) {
    tuple<bool, int, int> query{queries[k]};
    if(get<0>(query))
      res.push_back(dsu.connected(get<1>(query), get<2>(query)) ? "YES\n" : "NO\n");
    else {
      dsu.unify(get<1>(query), get<2>(query));
    }
  }

  for(auto it{res.rbegin()}; it != res.rend(); ++it) {
    cout << *it;
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

