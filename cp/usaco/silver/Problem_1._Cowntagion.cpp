#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
  int n{};
  cin >> n;

  vector<vector<int>> adj(n);
  bitset<100001> visited{};
  for(int i{}; i < n - 1; ++i) {
    ll x{}, y{};
    cin >> x >> y;
    --x; --y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  ll res{};
  queue<int> q{};
  q.push(0);
  
  while(!q.empty()) {
    int node{q.front()};
    q.pop();
    visited[node] = true;

    if(adj[node].empty())
      continue;

    ll curr{};
    for(int child : adj[node]) {
      if(visited[child])
        continue;

      ++curr;
      q.push(child);
    }
    res += curr + ceil(log2(1 + curr));
  }

  cout << res << '\n';
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

