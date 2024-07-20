#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{200'001};
ll colors[N];
vector<int> adj[N];
ll res[N];

set<ll> dfs(int curr, int prev = -1) {
  set<ll> s{};
  s.insert(colors[curr]);

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    set<ll> s2{dfs(node, curr)};
    if(s2.size() > s.size())
      swap(s, s2);
    for(int x : s2)
      s.insert(x);
  }

  res[curr] = s.size();
  return s;
}

void solve() {
  int n;
  cin >> n;

  for (size_t i = 0; i < n; i++) {
    cin >> colors[i];
  }

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  dfs(0);

  for(int i{}; i < n - 1; ++i) {
    cout << res[i] << ' ';
  }

  cout << res[n - 1] << '\n';
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

