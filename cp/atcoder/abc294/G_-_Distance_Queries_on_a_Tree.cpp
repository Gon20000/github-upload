#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;
using edge_t = pair<ll, ll>;

class BIT {
  vector<ll> arr{}, bit{};
int m_size{};

public:
  BIT(size_t size) : m_size{(int)size}, arr(size), bit(size + 1) {}

  void add(int pos, ll num) {
    arr[pos] += num;
    ++pos;

    for(; pos <= m_size; pos += pos & - pos)
      bit[pos] += num;
  }

  void set(int pos, ll num) {
    add(pos, num - arr[pos]);
  }

  ll sum(int pos) {
    ++pos;

    ll res{};
    for(; pos > 0; pos -= pos & -pos) 
      res += bit[pos];

    return res;
  }

  ll sumRange(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};

constexpr int N{200'001}, LOG{18};
sparse_t sparse(LOG, vector<ll>(N, -1));

vector<edge_t> adj[N];
vector<edge_t> edges(N);
int in[N], out[N], depth[N];
int idx{1};

void dfs(int curr, int prev, int dep, BIT& tour) {
  depth[curr] = dep;

  for(auto [node, w] : adj[curr]) {
    if(node == prev)
      continue;
    sparse[0][node] = curr;

    tour.set(idx, w);
    in[node] = idx++;
    dfs(node, curr, dep + 1, tour);
    tour.set(idx, 0 - w);
    out[node] = idx++;
  }
}

void initSparse(int n) {
  for(int i{1}; i < LOG; ++i) {
    for(int j{1}; j < n; ++j) {
      ll tmp{sparse[i - 1][j]};

      if(tmp != -1)
        sparse[i][j] = sparse[i - 1][tmp];
    }
  }
}

int kth_step(int x, int k) {
  if(k <= 0)
    return x;

  for(int i{}; i < LOG; ++i, k >>= 1) {
    if(k & 1)
      x = sparse[i][x];
  }

  return x;
}

pair<int, int> getLca(int x, int y) {
  y = kth_step(y, depth[y] - depth[x] - 1);

  if(x == sparse[0][y])
    return {-1, y};
  else if(depth[y] != depth[x])
    y = sparse[0][y];

  for(int i{LOG - 1}; i >= 0; --i) {
    if(sparse[i][x] == sparse[i][y])
      continue;

    x = sparse[i][x];
    y = sparse[i][y];
  }

  return {x, y};
}

void solve() {
  int n{};
  cin >> n;

  for(int i{}; i < n - 1; ++i) {
    ll x{}, y{}, w{};
    cin >> x >> y >> w;

    adj[--x].push_back({--y, w});
    adj[y].push_back({x, w});
    edges[i] = {x, y};
  }

  BIT tour(2 * n);
  // idk why but I feel like adding 0 
  tour.set(0, 0);
  in[0] = 0;
  dfs(0, -1, 0, tour);
  out[0] = idx;

  initSparse(n);

  int q{};
  cin >> q;

  while(q--) {
    int t{};
    cin >> t;

    if(t == 2) {
      int u{}, v{};
      cin >> u >> v;
      if(--u == --v) {
        cout << 0 << '\n';
        continue;
      }
      if(depth[u] > depth[v])
        swap(u, v);

      auto [u_parent, v_parent] = getLca(u, v);

      ll res{tour.sumRange(in[v_parent], in[v])};
      if(u_parent != -1)
        res += tour.sumRange(in[u_parent], in[u]);

      cout << res << '\n';
    }
    else {
      ll i{}, w{};
      cin >> i >> w;

      auto [x, y] = edges[--i];
      x = sparse[0][x] == y ? x : y;

      tour.set(in[x], w);
      tour.set(out[x], 0 - w);
    }
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

