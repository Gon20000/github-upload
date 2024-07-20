#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using sparse_t = vector<vector<ll>>;

class SegTree {
  vector<ll> arr{}, seg{};

public:
  SegTree(vector<ll> vec) : arr(vec), seg(4 * vec.size()) {
    build(0, 0, vec.size() - 1);
  }

  void recalc(int idx)
  {
    seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
  }

  void build(int idx, int left, int right)
  {
    if (left == right)
    {
      seg[idx] = arr[left]; // leaf node, gets appened to the end
    }
    else
  {
      int mid{left + (right - left) / 2};
      build(2 * idx + 1, left, mid);
      build(2 * idx + 2, mid + 1, right);
      recalc(idx);
    }
  }

  ll query(int idx, int left, int right, int x, int y)
  {
    if (x <= left && y >= right)
      return seg[idx];
    else
    {
      int mid{left + (right - left) / 2};
      ll res{};

      if (x <= mid)
      {
        res ^= query(2 * idx + 1, left, mid, x, y);
      }

      if (y > mid)
      {
        res ^= query(2 * idx + 2, mid + 1, right, x, y);
      }

      return res;
    }
  }

  void update(int idx, int left, int right, int pos, ll add)
  {
    if (left == pos && left == right)
    {
      seg[idx] = add; // leaf node
    }
    else
  {
      int mid{left + (right - left) / 2};

      if (pos <= mid)
      {
        update(2 * idx + 1, left, mid, pos, add);
      }

      else
    {
        update(2 * idx + 2, mid + 1, right, pos, add);
      }

      recalc(idx);
    }
  }
};

constexpr int N{100'001}, LOG{17};

vector<int> adj[N];
sparse_t sparse(LOG, vector<ll>(N, -1));
ll val[N];
int depth[N], in[N], out[N];
vector<ll> tour{};
int idx{};

void dfs_init(int curr, int prev, int dep = 0) {
  tour[idx] = val[curr];
  in[curr] = idx++;

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    sparse[0][node] = curr;
    dfs_init(node, curr, dep + 1);
    tour[idx] = val[node];
    out[node] = idx++;
  }

  depth[curr] = dep;
}

ll k_step(int node, int steps, const sparse_t& sparse) {
  for(int i{}; i < LOG; ++i) {
    if(steps & 1)
      node = sparse[i][node];
    steps >>= 1;
  }

  return node;
}

ll lca(int x, int y, const sparse_t& sparse) {
  if(depth[x] > depth[y])
    swap(y, x);

  if(depth[x] != depth[y]) 
    y = k_step(y, depth[y] - depth[x], sparse);

  if(x == y)
    return x;

  for(int i{LOG - 1}; i >= 0; --i) {
    if(sparse[i][x] == sparse[i][y])
      continue;

    x = sparse[i][x];
    y = sparse[i][y];
  }

  return sparse[0][x];
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  for(int i{}; i < n; ++i)
    cin >> val[i];

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  tour.resize(2 * n);
  dfs_init(0, -1);

  for(int i{1}; i < LOG; ++i) {
    for(int j{1}; j < n; ++j) {
      if(sparse[i - 1][j] == -1)
        continue;

      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  SegTree seg{tour};
  while(q--) {
    int t{}, x{}, y{};
    cin >> t >> x >> y;
    --x;

    if(t == 2) {

      ll parent{lca(x, --y, sparse)};
      ll first{seg.query(0, 0, 2 * n - 1, in[parent], in[x])};
      ll second{seg.query(0, 0, 2 * n - 1, in[parent], in[y])};

      cout << (first ^ second ^ val[parent]) << '\n';
    }
    else {
      val[x] = y;
      seg.update(0, 0, 2 * n - 1, in[x], y);
      if(out[x])
        seg.update(0, 0, 2 * n - 1, out[x], y);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("cowland.in", "r", stdin);
  freopen("cowland.out", "w", stdout);

  int t{1};
  /*cin >> t;*/

  while(t--)
    solve();

  return 0;
}


