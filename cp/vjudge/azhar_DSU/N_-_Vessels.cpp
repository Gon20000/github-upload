#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
  vector<int> m_p{}, m_size{};

public:
  vector<ll> m_sums{};
  DSU(int size, const vector<ll>& sums) : m_p(size), m_size(size, 1), m_sums(sums) {
    for(int i{}; i < size; ++i)
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

    m_p[y_root] = x_root;
    m_size[x_root] += m_size[y_root];
  }

  void add(int vessel, ll c) {
    while(c > 0) {
      vessel = get(vessel);
      if(m_sums[vessel] >= c) {
        m_sums[vessel] -= c;
        c = 0;
      }
      else {
        c -= m_sums[vessel];
        m_sums[vessel] = 0;
        
        if(vessel != m_p.size() - 1) {
          unify(vessel, vessel + 1);
        }
        else
          break;
      }
    }
  }
};

void solve() {
  int n{};
  cin >> n;

  vector<ll> cap(n);
  for(ll& x : cap)
    cin >> x;

  DSU dsu(n, cap);

  int m{};
  cin >> m;
  while(m--) {
    ll q{}, v{}, c{};
    cin  >> q >> v;

    --v;
    if(q == 2) {
      cout << cap[v] - dsu.m_sums[v] << '\n';
    }
    else {
      cin >> c;
      dsu.add(v, c);
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

