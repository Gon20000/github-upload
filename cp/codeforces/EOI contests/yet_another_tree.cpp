#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using tree_t = vector<vector<int>>;

ll res{};

ll sum(ll x)
{
    return (x * (x + 1)) / 2;
}

void solve(tree_t tree, int curr, ll low, ll high, ll cnt, ll inv_cnt)
{
    ++res;

    if (curr > high)
    {
        ++cnt;
        res += sum(inv_cnt);
        inv_cnt = 0;
    }
    else if (curr < high)
    {
        ++inv_cnt;
        res += sum(cnt);
        cnt = 0;
    }

    if(tree[curr].empty()) {
        res += sum(cnt) + sum(inv_cnt);
        return;
    }

    for (int i{}; i < tree[curr].size(); ++i)
    {
        solve(tree, tree[curr][i], low, curr, cnt, inv_cnt);
        if(i > 0)
            res -= cnt;
    }

}
int main()
{
    res = 0;
    int n{};
    cin >> n;

    tree_t tree(n + 1);

    --n;
    while (n--)
    {
        int x{}, y{};
        cin >> x >> y;

        tree[x].push_back(y);
    }

    solve(tree, 1, 1, 1, 0, 0);
    cout << res << '\n';
}