#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr size_t max_n{200'001};
vector<int> adj[max_n];
ll sums[max_n], cnt[max_n];

void dfs1(int curr, int prev) {
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    dfs1(node, curr);
    cnt[curr] += cnt[node] + 1;
    sums[curr] += 1 + cnt[node] + sums[node];
  }
}

void dfs2(int curr, int prev) {
  ll currCnt{cnt[curr]}, currSum{sums[curr]};
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    sums[node] += (currSum - sums[node] - cnt[node] - 1) + (cnt[0] - cnt[node]);
    dfs2(node, curr);
  }
}

void solve() {
  int n{};
  cin >> n;

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;
    --x; --y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  
  dfs1(0, -1);
  dfs2(0, -1);

  for(int i{0}; i < n - 1; ++i)
    cout << sums[i] << ' ';
  cout << sums[n - 1] << '\n';
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

