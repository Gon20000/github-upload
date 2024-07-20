#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
  vector<int> m_p{}, m_size{};
  vector<ll> m_color{};

public:
  DSU(int n) : m_p(n), m_size(n, 1), m_color(n) {
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

    if(x_root < y_root)
      swap(x_root, y_root);

    m_size[x_root] += m_size[y_root];
    m_p[y_root] = x_root;
  }

  void addColor(int x, int y, ll c) {
    m_p[y] = y;
    m_color[y] = c;

    if(x != y) { 
      int x_root{get(x)};

      if(x_root < y)
        unify(x_root, y);
    }
  }

  ll getRes(int x) {
    return m_color[m_p[x]];
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{}, q{};
  cin >> n >> q;

  DSU dsu{n};
  for(int i{}; i < n - 1; ++i)
    dsu.unify(i, i + 1);

  while(q--) {
    ll x{}, y{}, c{};
    cin >> x >> y >> c;

    dsu.addColor(--x, --y, c);
  }

  for(int i{}; i < n; ++i) 
    cout << dsu.getRes(i) << '\n';
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

