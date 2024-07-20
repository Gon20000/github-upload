#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class DSU {
  vector<int> m_p{}, m_size{};
  vector<ll> m_sum{};

public:
  DSU(int size) : m_p(size), m_size(size), m_sum(size) {
    for(int i{}; i < size; ++i) {
      m_p[i] = i;
    }
  }

  pair<int, int> get(int x) {
    if(m_p[x] == x)
      return {x, 0};

    pair<int, int> res{get(m_p[x])};
    m_sum[x] += res.second;
    m_p[x] = res.first;

    return {res.first, m_sum[x]};
  }

  void unify(int x, int y) {
    int p_x{get(x).first}, p_y{get(y).first};

    if(p_x == p_y)
      return;

    if(m_size[p_x] < m_size[p_y])
      swap(p_x, p_y);
    
    m_size[p_x] += m_size[p_y];
    m_p[p_y] = p_x;
    m_sum[p_y] -= m_sum[p_x];
  }

  void addExp(int x, int exp) {
    x = get(x).first;
    m_sum[x] += exp;
  }

  ll getExp(int x) {
    int p_x{get(x).first};

    return m_sum[x] + (m_p[x] == x ? 0 : m_sum[m_p[x]]);
  }
};

void solve() {
  int n{}, m{};
  cin >> n >> m;

  DSU dsu{n};
  while(m--) {
    string str{};
    cin >> str;

    if(str[0] == 'a') {
      ll x{}, exp{};
      cin >> x >> exp;

      dsu.addExp(--x, exp);
    }
    else if(str[0] == 'j') {
      int x{}, y{};
      cin >> x >> y;
      --x; --y;

      dsu.unify(x, y);
    }
    else {
      int x{};
      cin >> x;

      cout << dsu.getExp(--x) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};

  while(t--)
    solve();

  return 0;
}


