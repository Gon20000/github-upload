#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

using ll = long long;
using ld = long double;

ld dfs(int curr, int prev, const vector<vector<int>>& adj) {
  ld res{};

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    res += 1 + dfs(node, curr, adj);
  }

  if(res != 0) 
    res /= adj[curr].size() - (prev != -1);
  return res;
}

void solve() {
  int n{};
  cin >> n;

  vector<vector<int>> adj(n + 1);

  for (size_t i = 0; i < n - 1; i++) {
    int x{}, y{};
    cin >> x >> y;

    adj[y].push_back(x);
    adj[x].push_back(y);
  }

  ld res{dfs(1, -1, adj)};
  cout << setprecision(10) << res << '\n';
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

