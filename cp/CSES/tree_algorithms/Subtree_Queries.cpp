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

constexpr int N{200000};
vector<ll> adj[N];
vector<ll> values(N);
int i{};

ll dfs(int curr, int prev, vector<ll>& order, vector<ll>& sizes, vector<ll>& newValues) {
  int idx{i++};
  order[curr] = idx;
  newValues[idx] = values[curr];

  for(int node : adj[curr]) {
    if(node == prev)
      continue;

    sizes[idx] += dfs(node, curr, order, sizes, newValues);
  }

  return sizes[idx];
}

void solve() {
  int n{}, q{};
  cin >> n >> q;

  for(int i{}; i < n; ++i)
    cin >> values[i];

  for(int i{}; i < n - 1; ++i) {
    int x{}, y{};
    cin >> x >> y;

    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  vector<ll> order(n), sizes(n, 1), sums(n);

  dfs(0, -1, order, sizes, sums);

  SegTree seg{sums};

  while(q--) {
    ll t{}, s{}, x{};
    cin >> t >> s;
    --s;

    if(t == 2) {
      cout << seg.query(0, 0, n - 1, order[s], order[s] + sizes[order[s]] - 1) << '\n';
    }
    else {
      cin >> x;
      seg.update(0, 0, n - 1, order[s], x);
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
