#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define int ll

class DSU {
  vector<ll> m_p{}, m_size{}, m_sum{};
  ll max_sum{};

public:
  DSU(int n) : m_p(n), m_size(n, 1), m_sum(n) {
    for(int i{}; i < n; ++i)
      m_p[i] = i;
  }

  int get(int x) {
    return m_p[x] = (m_p[x] == x ? x : get(m_p[x]));
  }

  void unify(int x, int y, ll a) {
    int x_root{get(x)}, y_root{get(y)};
    
    if(m_size[x_root] < m_size[y_root])
      swap(x_root, y_root);

    m_sum[x_root] += a;
    max_sum = max(max_sum, m_sum[x_root]);

    if(x_root == y_root)
      return;

    m_size[x_root] += m_size[y_root];
    m_p[y_root] = x_root;
    m_sum[x_root] += m_sum[y_root];
    max_sum = max(max_sum, m_sum[x_root]);
  }

  int getRes() {
    return max_sum;
  }

  bool connected(int x, int y) {
    return get(x) == get(y);
  }
};

void solve() {
  int n{};
  cin >> n;

  vector<ll> arr(n), order(n);
  for(ll& x : arr)
    cin >> x;
  for(ll& x : order)
    cin >> x;

  DSU dsu{n};
  vector<ll> res(n);
  for(int i{n - 1}; i >= 0; --i) {
    res[i] = dsu.getRes();
    --order[i];
    dsu.unify(order[i], min(order[i] + 1, (ll)n - 1), arr[order[i]]);
  }

  for(int i{}; i < n; ++i)
    cout << res[i] << '\n';
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

