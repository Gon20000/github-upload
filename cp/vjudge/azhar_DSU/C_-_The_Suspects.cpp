#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
  vector<int> m_p{}, m_size{};
  int cnt{};

public:
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

  int getRes() {
    return m_size[get(0)];
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{1}, m{};
  cin >> n >> m;
  while(n != 0) {
    DSU dsu{n};
    while(m--) {
      int k{};
      cin >> k;

      int x{};
      cin >> x;

      for(int i{1}; i < k; ++i) {
        int y{};
        cin >> y;
        dsu.unify(x, y);
      }
    }
    cout << dsu.getRes() << '\n';
    cin >> n >> m;
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

