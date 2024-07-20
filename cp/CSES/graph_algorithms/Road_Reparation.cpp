#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using edge_t = tuple<int, int, ll>;

class DSU {
  vector<int> m_p{}, m_size{};

public:
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

  int getRes() {
    return m_size[get(0)];
  }
};

void solve() {
  int n{}, m{};
  cin >> n >> m;

  DSU dsu{n};

  vector<edge_t> arr(m);
  for(auto& edge : arr) {
    int x{}, y{};
    ll c{};
    cin >> x >> y >> c;

    edge = {--x, --y, c};
  }

  sort(arr.begin(), arr.end(), [&](const edge_t& x, const edge_t& y) {
    return get<2>(x) < get<2>(y);
  });

  ll res{};
  for(int i{}; i < m; ++i) {
    auto [x, y, c] = arr[i];

    if(!dsu.unify(x, y))
      continue;

    res += c;
  }

  if(dsu.getRes() == n)
    cout << res << '\n';
  else {
    cout << "IMPOSSIBLE\n";
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

