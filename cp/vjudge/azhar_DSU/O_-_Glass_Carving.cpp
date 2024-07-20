#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int max_dim{200'000};

class DSU {
  vector<int> m_p{}, m_size{};
  int cnt{1};

public:
  DSU(int size) : m_p(size), m_size(size, 1) {
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
    cnt = max(cnt, m_size[x_root]);
  }

  ll getRes() {
    return cnt;
  }

};

void solve() {
  int w{}, h{}, n{};
  cin >> w >> h >> n;

  DSU rows{h}, cols{w};

  vector<bool> visited_rows(h + 1), visited_cols(w + 1);
  vector<pair<char, int>> arr(n);
  for(auto& [x, dim] : arr){
    cin >> x >> dim;

    if(x == 'H')
      visited_rows[--dim] = 1;
    else
      visited_cols[--dim] = 1;
  }

  for(int i{}; i < h - 1; ++i) {
    if(visited_rows[i])
      continue;

    rows.unify(i, i + 1);
  }

  for(int i{}; i < w - 1; ++i) {
    if(visited_cols[i])
      continue;

    cols.unify(i, i + 1);
  }

  vector<ll> res(n);
  for(int i{n - 1}; i >= 0; --i) {
    auto [x, dim] = arr[i];

    res[i] = rows.getRes() * cols.getRes();

    if(x == 'H') {
      /*if(dim > 0 && !visited_rows[dim - 1])*/
      /*  rows.unify(dim, dim - 1);*/
      rows.unify(dim, dim + 1);

      /*visited_rows[dim] = 0;*/
    }
    else {
      /*if(dim > 0 && !visited_cols[dim - 1])*/
      /*  cols.unify(dim, dim - 1);*/
      cols.unify(dim, dim + 1);
      /*visited_cols[dim] = 0;*/
    }
  }
  
  for(ll x : res)
    cout << x << '\n';
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

