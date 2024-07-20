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
    return cnt - 1;
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{1}, m{}, res{};
  cin >> n >> m;

  vector<vector<int>> mp(m);
  DSU dsu{n};

  for(int i{}; i < n; ++i) {
    int k{};
    cin >> k;
    res += (k == 0);

    while(k--) {
      int lang{};
      cin >> lang;
      
      for(int employee : mp[--lang]) {
        dsu.unify(i, employee);
      }
      mp[lang].push_back(i);
    }
  }

  cout << max(res, dsu.getRes()) << '\n';
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

