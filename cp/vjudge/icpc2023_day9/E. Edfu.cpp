#include <bits/stdc++.h>
#include <bitset>
using namespace std;

using ll = long long;
using ld = long double;

constexpr int mx{5000};

vector<map<ll, ll>> arr(50'000);

map<ll, ll> factorize(ll x) {
  map<ll, ll> mp{};

  for(int i{2}; i * i <= x; ++i) {
    if(x % i != 0)
      continue;

    x /= i;
    ++mp[i];
  }

  return mp;
} 

struct segNode {
  bitset<mx> val{};
  bitset<mx> lazy{};
};

class SegTree {
  vector<segNode> seg{};

public:
  SegTree(size_t size) : seg(4 * size) {
    build(0, 0, size - 1);
  }

  void recalc(int idx)
  {
    seg[idx].val = seg[2 * idx + 1].val | seg[2 * idx + 2].val;
  }

  void build(int idx, int left, int right)
  {
    if (left == right)
    {
      seg[idx].val = arr[left]; // leaf node, gets appened to the end
    }
    else
  {
      int mid{left + (right - left) / 2};
      build(2 * idx + 1, left, mid);
      build(2 * idx + 2, mid + 1, right);
      recalc(idx);
    }
  }

  void propagate(int idx, int left, int right) {
    // overflow
    seg[idx].val |= seg[idx].lazy;

    if (left < right) {
      seg[2 * idx + 1].lazy |= seg[idx].lazy;
      seg[2 * idx + 2].lazy |= seg[idx].lazy;
    }

    seg[idx].lazy = 1;
  }

  bitset<mx> query(int idx, int left, int right, int x, int y) {
    propagate(idx, left, right);

    if (x <= left && y >= right)
      return seg[idx].val;

    int mid{left + (right - left) / 2};

    bitset<mx> res{};
    if (x <= mid) {
      res |= query(2 * idx + 1, left, mid, x, y);
    }
    if (y > mid) {
      res |= query(2 * idx + 2, mid + 1, right, x, y);
    }

    return res;
  }


  void update(int idx, int left, int right, int x, int y, bitset<mx> add)
  {
    propagate(idx, left, right);
    if (x <= left && y >= right)
    {
      seg[idx].lazy |= add; // included in the segment
      return;
    }

    int mid{left + (right - left) / 2};

    if (x <= mid)
    {
      update(2 * idx + 1, left, mid, x, y, add);
    }

    if (y > mid)
    {
      update(2 * idx + 2, mid + 1, right, x, y, add);
    }

    propagate(2 * idx + 1, left, mid);
    propagate(2 * idx + 2, mid + 1, right);
    recalc(idx);
  }
};

void solve() {
  int n{}, q{};
  cin >> n >> q;

  vector<ll> arr(n);
  for(ll& x : arr)
    cin >> x;

  SegTree seg(n);
  
  while(q--) {
    string str{};
    int l{}, r{};
    cin >> str >> l >> r;

    if(str[0] == 'A') {
      ll x{seg.query(0, 0, n - 1, --l, --r)};

      for(int i{11}; i >= 0; --i) {
        if(x % fac[i] == 0) {
          cout << i + 1 << '\n';
          break;
        }
      }
    }
    else {
      ll x{};
      cin >> x;
      seg.update(0, 0, n - 1, --l, --r, x);
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

