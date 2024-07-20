#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{200'001};

vector<int> adj[N], depArr[N];
int depth[N], in[N], out[N];
int idx{};

void dfs_init(int curr, int prev, int dep = 0) {
  in[curr] = idx;
  depArr[dep].push_back(idx++);
  depth[curr] = dep;

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    dfs_init(node, curr, dep + 1);
  }
  out[curr] = idx++;
}

void solve() {
  int n{}, q{};
  cin >> n;

  for(int i{1}; i < n; ++i) {
    int x{};
    cin >> x;

    adj[i].push_back(--x);
    adj[x].push_back(i);
  }

  dfs_init(0, -1);

  cin >> q;
  while(q--) {
    int u{}, d{};
    cin >> u >> d;
    --u;

    if(d <= depth[u]) {
      cout << (d == depth[u]) << '\n';
      continue;
    }

    ll res{upper_bound(depArr[d].begin(), depArr[d].end(), out[u]) 
      - lower_bound(depArr[d].begin(), depArr[d].end(), in[u])};

    cout << res << '\n';
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


