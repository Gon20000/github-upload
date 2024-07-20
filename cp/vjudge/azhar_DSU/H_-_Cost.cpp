#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using edge_t = tuple<ll, int, int>;

constexpr ll mod{static_cast<ll>(1e9)};

void add(ll& x, ll y) {
  x = (x % mod + y % mod) % mod;
}

ll mult(ll x, ll y) {
  return ((x % mod) * (y % mod)) % mod;
}

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

  int getSize(int x) {
    return m_size[get(x)];
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<edge_t> edges(m);
  DSU dsu{n};
  ll W{}, res{};
  for(int i{}; i < m; ++i) {
    int u{}, v{};
    ll w{};
    cin >> u >> v >> w;

    edges[i] = {w, --u, --v};
    W += w;
  }

  sort(edges.begin(), edges.end(), [&](const edge_t& a, const edge_t& b) {
    return get<0>(a) > get<0>(b);
  });

  for(const edge_t& edge : edges) {
    int u{get<1>(edge)}, v{get<2>(edge)};
    if(!dsu.connected(u, v)) {
      add(res, mult(mult(W, dsu.getSize(u)), dsu.getSize(v)));
      res %= mod;
      dsu.unify(u, v);
    }

    W -= get<0>(edge);
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

