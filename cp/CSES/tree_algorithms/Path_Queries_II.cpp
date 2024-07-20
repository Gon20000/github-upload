#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int N{200'001}, S{1 << 19};
vector<int> adj[N];
vector<int> sz(N, 1), in(N), heavy(N), depth(N), p(N);
vector<ll> val(N), seg(S);
int idx{}, n{};

void update(int idx, int val) {
  seg[idx += n] = val;
  for (idx /= 2; idx; idx /= 2) seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
}


ll query(int lo, int hi) {

  ll ra = 0, rb = 0;

  for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
    if (lo & 1) ra = max(ra, seg[lo++]);
    if (hi & 1) rb = max(rb, seg[--hi]);
  }

  return max(ra, rb);
}

void dfs_sz(int curr, int prev) {
  p[curr] = prev;

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    depth[node] = depth[curr] + 1;

    dfs_sz(node, curr);
    sz[curr] += sz[node];
  }

}


void dfs_hld(int curr, int prev, int top = 0) {
  update(idx, val[curr]);
  in[curr] = idx++;
  heavy[curr] = top;
  int h_chi = -1, h_sz = -1;

  for (int chi : adj[curr]) {
    if (chi == prev) continue;

    if (sz[chi] > h_sz) {
      h_sz = sz[chi];
      h_chi = chi;
    }
  }

  if (h_chi == -1) return;

  dfs_hld(h_chi, curr, top);

  for (int chi : adj[curr]) {
    if (chi == prev || chi == h_chi) continue;
    dfs_hld(chi, curr, chi);
  }
}

ll getQuery(int x, int y) {
  ll res{0};
  while(heavy[x] != heavy[y]) {
    if(depth[heavy[x]] > depth[heavy[y]])
      swap(x, y);

    res = max(res, query(in[heavy[y]], in[y]));
    y = p[heavy[y]];
  }

  if(depth[x] > depth[y])
    swap(x, y);

  return max(res, query(in[x], in[y]));
}

void solve() {
  int q{};
  cin >> n >> q;

  for(int i{}; i < n; ++i) {
    cin >> val[i];
    heavy[i] = i;
  }

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  dfs_sz(0, -1);
  dfs_hld(0, -1);


  vector<ll> res{};
  while(q--) { 
    ll t{}, x{}, y{};
    cin >> t >> x >> y;

    if(t == 1) {
      update(in[--x], y);
    }
    else {
      res.push_back(getQuery(--x, --y));
    }
  }

  for(int i{}; i < (int)res.size() - 1; ++i)
    cout << res[i] << ' ';
  cout << res.back() << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  /*freopen("in", "r", stdin);*/

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}
