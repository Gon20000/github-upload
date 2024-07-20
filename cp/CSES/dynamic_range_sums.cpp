#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int max_size{200000};
ll arr[max_size];
ll seg[4 * max_size];

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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n{}, q{};
  cin >> n >> q;

  for (int i{}; i < n; ++i)
  {
    cin >> arr[i];
  }

  build(0, 0, n - 1);

  while (q--)
  {
    ll mode{}, low{}, high{};
    cin >> mode >> low >> high;

    if (mode == 2)
      cout << query(0, 0, n - 1, low - 1, high - 1) << '\n';
    else
    {
      update(0, 0, n - 1, low - 1, high);
    }
  }
}
