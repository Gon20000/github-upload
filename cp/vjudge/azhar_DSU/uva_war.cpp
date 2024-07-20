#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
  vector<int> m_p{}, m_size{}, m_enemy{};

public:
  DSU(int n) : m_p(n), m_size(n, 1), m_enemy(n, -1) {
    for(int i{}; i < n; ++i)
      m_p[i] = i;
  }

  int get(int x) {
    return m_p[x] = (m_p[x] == x ? x : get(m_p[x]));
  }

  void unify(int x, int y) {
    if(x == -1 || y == -1)
      return;

    int x_root{get(x)}, y_root{get(y)};

    if(x_root == y_root)
      return;

    if(m_size[x_root] < m_size[y_root])
      swap(x_root, y_root);

    int y_enemy{getEnemy(y)};
    if(m_enemy[x_root] == -1)
      m_enemy[x_root] = y_enemy;

    m_size[x_root] += m_size[y_root];
    m_p[y_root] = x_root;
  }

  int getEnemy(int x) {
    if(x == -1)
      return -1;

    x = m_enemy[get(x)];

    return x == -1 ? x : get(x);
  }

  void addEnemy(int x, int y) {
    if(x == -1 || y == -1)
      return;

    x = get(x);
    y = get(y);
    int enemy_x{getEnemy(x)}, enemy_y{getEnemy(y)};

    if(enemy_y != -1)
      unify(x, enemy_y);
    else 
      m_enemy[y] = x;



    if(enemy_x != -1)
      unify(y, enemy_x);
    else
      m_enemy[x] = y;
  }

  void addFriend(int x, int y) {
    unify(getEnemy(x), getEnemy(y));
    unify(x, y);
  }

  bool isEnemy(int x, int y) {
    if(x == -1 || y == -1)
      return false;

    x = get(x);
    y = get(y);

    bool res{false};

    if(getEnemy(x) != -1) {
      res = connected(m_enemy[x], y);
    }

    if(getEnemy(y) != -1)
      res |= connected(m_enemy[y], x);

    return res;
  }

  bool connected(int x, int y) {
    if(x == -1 || y == -1)
      return false;
    return get(x) == get(y);
  }
};

void solve() {
  int n{};
  cin >> n;

  DSU dsu{n};
  int c{}, x{}, y{};
  cin >> c >> x >> y;

  while(c != 0) {
    switch(c) {
      case 1:
        if(dsu.isEnemy(x, y) || dsu.isEnemy(dsu.getEnemy(x), dsu.getEnemy(y))) 
          cout << -1 << '\n';
        else
          dsu.addFriend(x, y);
        break;

      case 2:
        if(dsu.connected(x, y) || dsu.connected(dsu.getEnemy(x), dsu.getEnemy(y)))
          cout << -1 << '\n';
        else {
          dsu.addEnemy(x, y);
        }
        break;
      case 3:
        cout << (dsu.connected(x, y) || 
          (dsu.connected(dsu.getEnemy(x), dsu.getEnemy(y)))) << '\n';
        break;
      case 4:
        cout << dsu.isEnemy(x, y) << '\n';
        break;
    }
    cin >> c >> x >> y;
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


