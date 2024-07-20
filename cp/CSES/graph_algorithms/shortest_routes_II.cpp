#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, m{}, q{};
  cin >> n >> m >> q;
  
  vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));

  for(int i{1}; i <= n; ++i)
    dist[i][i] = 0;

  while(m--) {
    ll x{}, y{}, w{};
    cin >> x >> y >> w;
    dist[x][y] = min(dist[x][y], w);
    dist[y][x] = dist[x][y];
  }

  for(int k{1}; k <= n; ++k) {
    for(int i{1}; i <= n; ++i) {
      for(int j{i + 1}; j <= n; ++j) {
        if(max(dist[k][i], dist[k][j]) == LLONG_MAX)
            continue;

        dist[i][j] = min(dist[i][j], dist[k][i] + dist[k][j]);
        dist[j][i] = min(dist[j][i], dist[k][i] + dist[k][j]);
      }
    }
  }

  while(q--) {
    ll x{}, y{};
    cin >> x >> y;

    if(x > n || y > n) {
      cout << -1 << '\n';
      continue;
    }
    
    cout << (dist[x][y] == LLONG_MAX ? -1 : dist[x][y]) << '\n';
  }

  return 0;
}

