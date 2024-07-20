#include <bits/stdc++.h>
#include <climits>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;

constexpr int LOG{19};
void solve() {
  int n{}, q{};
  cin >> n >> q;

  sparse_t sparse(LOG, vector<ll>(n, LLONG_MAX));
  for(int i{}; i < n; ++i) {
    ll x{};
    cin >> x;

    sparse[0][i] = x;
  }

  for(int i{1}; i < LOG; ++i) {
    for(int j{0}; j < n; ++j) {
      ll x{sparse[i - 1][j]};

      int idx{j + (1 << (i - 1))};
      if(idx < n)
        x = min(x, sparse[i - 1][idx]);
      sparse[i][j] = x;
    }
  }

  while(q--) {
    ll x{}, y{};
    cin >> x >> y;

    ll num{static_cast<ll>(floor(log2(y - x)))};

    cout << min(sparse[num][x], sparse[num][y - (1 << num)]) << '\n';
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

