#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using edge_t = tuple<ll, int, int>;

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
  int n{}, m{};
  cin >> n >> m;

  DSU dsu{n + 1};
  vector<int> arr(n + 1);
  while (m--) {
    int x{}, y{};
    cin >> x >> y;

    if(dsu.connected(x, y)) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    if(arr[x]) 
      dsu.unify(arr[x], y);
    if(arr[y])
      dsu.unify(arr[y], x);

    arr[x] = y;
    arr[y] = x;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("meciul.in", "r", stdin);
  freopen("meciul.out", "w", stdout);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}

