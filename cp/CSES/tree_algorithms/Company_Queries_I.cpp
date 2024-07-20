#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;

constexpr int LOG{18};
void solve() {
  int n{}, q{};
  cin >> n >> q;

  sparse_t sparse(LOG, vector<ll>(n, -1));
  for(int i{1}; i < n; ++i) {
    cin >> sparse[0][i];
    --sparse[0][i];
  }

  for(int i{1}; i < LOG; ++i) {
    for(int j{}; j < n; ++j) {
      ll tmp{sparse[i - 1][j]};

      if(tmp == -1)
        continue;
      sparse[i][j] = sparse[i - 1][tmp];
    }
  }

  while(q--) {
    int u{}, k{};
    cin >> u >> k;

    --u;
    for(int i{}; k > 0 && u != -1; ++i, k >>= 1) {
      if(k & 1)
        u = sparse[i][u];
    }

    cout << (u == -1 ? u : u + 1) << '\n';
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

