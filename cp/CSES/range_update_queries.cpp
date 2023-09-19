#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct segNode {
    ll val{};
    ll lazy{};
};

const int max_size{200000};
ll arr[max_size];
segNode seg[4 * max_size];

void recalc(int idx)
{
    seg[idx].val = seg[2 * idx + 1].val + seg[2 * idx + 2].val;
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
    seg[idx].val += (left - right + 1) * seg[idx].lazy;

    if (left < right) {
        seg[2 * idx + 1].lazy += seg[idx].lazy;
        seg[2 * idx + 2].lazy += seg[idx].lazy;
    }

    seg[idx].lazy = 0;
}

ll query(int idx, int left, int right, int pos) {
    propagate(idx, left, right);

    if (pos == left && left == right)
        return seg[idx].val;

    int mid{left + (right - left) / 2};

    if (pos <= mid) {
        return query(2 * idx + 1, left, mid, pos);
    }
    else {
        return query(2 * idx + 2, mid + 1, right, pos);
    }
}


void update(int idx, int left, int right, int x, int y, ll add)
{
    propagate(idx, left, right);
    if (x <= left && y >= right)
    {
        seg[idx].lazy += add; // included in the segment
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

int main() {
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
        int mode{};
        cin >> mode;

        if (mode == 2) {
            int index{};
            cin >> index;

            cout << query(0, 0, n - 1, index - 1) << '\n';
        }
        else
        {
            ll low{}, high{}, val{};
            cin >> low >> high >> val;

            update(0, 0, n - 1, low - 1, high - 1, val);
        }
    }
}