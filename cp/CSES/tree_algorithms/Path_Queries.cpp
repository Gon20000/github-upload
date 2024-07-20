#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

class SegTree {
  vector<ll> arr{}, seg{};

public:
  SegTree(vector<ll> vec) : arr(vec), seg(4 * vec.size()) {
    build(0, 0, vec.size() - 1);
  }

  void recalc(int idx)
  {
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
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
        res += query(2 * idx + 1, left, mid, x, y);
      }

      if (y > mid)
      {
        res += query(2 * idx + 2, mid + 1, right, x, y);
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

constexpr int N{200'001};
vector<int> adj[N];
ll val[N], in[N], out[N];
vector<ll> tour(2 * N);
ll idx{};

ll dfs(int curr, int prev) {
  tour[idx] = val[curr];
  in[curr] = idx++;

  /*ll sum{};*/
  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    ll x{dfs(node, curr)};
    tour[idx] -= x;
    out[node] = idx++;
    /*sum = x;*/
  }

  return /*sum + */val[curr];
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

  dfs(0, -1);
  tour.resize(2 * n);

  SegTree seg{tour};
  while(q--) {
    int t{}, u{};
    cin >> t >> u;
    --u;

    if(t == 1) {
      ll x{};
      cin >> x;

      seg.update(0, 0, 2 * n - 1, in[u], x);
      if(out[u])
        seg.update(0, 0, 2 * n - 1, out[u], 0 - x);
    }
    else {
      cout << seg.query(0, 0, 2*n-1, in[0], in[u]) << '\n';
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

