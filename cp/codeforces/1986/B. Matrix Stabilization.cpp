#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using grid_t = vector<vector<ll>>;

ll getMax(int i, int j, grid_t& grid) {
  ll res{0};
  if(i > 0)
    res = max(res, grid[i - 1][j]);
  if(i < grid.size() - 1)
    res = max(res, grid[i + 1][j]);
  if(j > 0)
    res = max(res, grid[i][j - 1]);
  if(j < grid[0].size() - 1)
    res = max(res, grid[i][j + 1]);

  return res;
}

void solve() {
  int n{}, m{};
  cin >> n >> m;

  grid_t grid(n, vector<ll>(m));
  for(int i{}; i < n; ++i) {
    for(int j{}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  for(int i{}; i < n; ++i) {
    for(int j{}; j < m; ++j) {
      ll high{getMax(i, j, grid)};
      if(grid[i][j] > high)
        grid[i][j] = high;
    }
  }

  for(int i{}; i < n; ++i) {
    for(int j{}; j < m - 1; ++j)
      cout << grid[i][j] << ' ';
    cout << grid[i].back() << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{1};
  cin >> t;

  while(t--)
    solve();

  return 0;
}


