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

  bool unify(int x, int y) {
    int x_root{get(x)}, y_root{get(y)};
    if(x_root == y_root)
      return false;

    if(m_size[x_root] < m_size[y_root])
      swap(x_root, y_root);

    m_size[x_root] += m_size[y_root];
    m_p[y_root] = x_root;

    return true;
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{};
  cin >> n;

  vector<pair<int, int>> bad{};
  DSU dsu{n + 1};
  for(int i{1}; i < n; ++i) {
    int x{}, y{};
    cin >> x >> y;

    if(!dsu.unify(x, y)) 
      bad.push_back({x, y});
  }

  cout << bad.size() << '\n';

  int parent{1};
  for(int i{}; i < bad.size(); ++i) {
    for(int j{parent + 1}; j <= n; ++j) {
      if(dsu.unify(parent, j)) {
        cout << bad[i].first << ' ' << bad[i].second << ' ' << parent << ' ' << j << '\n';
        parent = j;
        break;
      }
    }
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

