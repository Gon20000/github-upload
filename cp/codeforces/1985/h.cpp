#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void verify(pair<ll, ll>& high, map<ll, ll>& mp, ll key, int n) {
  if(key < 0 || key >= n)
    return;

  if(high.second < mp[key])
    high = {key, mp[key]};
}

void solve() {
  int n{}, m{};
  cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));

  for(int i{}; i < n; ++i) {
    for(int j{}; j < m; ++j) {
      cin >> grid[i][j];
    }
  }

  map<ll, set<ll>> rows{};
  map<ll, set<ll>> cols{};

  for(int i{}; i < n; ++i) {
    for(int j{}; j < m; ++j) {
      if(grid[i][j] != '#')
        continue;

      if(j < m - 1 && grid[i][j + 1] == '.') {
        rows[i].insert(j + 1);
        cols[j + 1].insert(i);
      }
      if(j > 0 && grid[i][j - 1] == '.') {
        rows[i].insert(j - 1);
        cols[j - 1].insert(i);
      }

      if(i > 0 && grid[i - 1][j] == '.') {
        rows[i - 1].insert(j);
        cols[j].insert(i - 1);
      }
      
      if(i < n - 1 && grid[i + 1][j] == '.') {
        rows[i + 1].insert(j);
        cols[j].insert(i + 1);
      }
    }
  }

  pair<ll, ll> high1{}, high2{};
  for(auto& [a,b] : rows) {
    if(b.size() > high1.second) {
      high1 = {a, b.size()};
    }
  }

  for(auto& [a,b] : cols) {
    if(b.size() > high2.second) {
      high2 = {a, b.size()};
    }
  }

  if(high2.second > high1.second) {
    high1 = {-1, -1};
  }
  else if(high1.second > high2.second) {
    high2 = {-1, -1};
  }

  if(high1.second != -1) {
    for(int i{}; i < m; ++i) {
      grid[high1.first][i] = '#';
    }
  }
  else {
    for(int i{}; i < n; ++i) {
      grid[i][high2.first] = '#';
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t{};
  cin >> t;
  while(t--)
    solve();
  
  return 0;
}
