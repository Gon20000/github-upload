#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string inp{};
map<char, vector<size_t>> mp{};

size_t helper(char x, char y)
{
    if (mp.find(x) == mp.end() || mp.find(y) == mp.end())
        return INT_MAX;

    vector<size_t> &v1{mp.find(x)->second};
    vector<size_t> &v2{mp.find(y)->second};

    for (int i{v1.size() - 1}; i >= 0 && !v2.empty(); --i)
    {
        if (v1[i] < v2.back())
            return inp.size() - v1[i] - 2;
    }

    return INT_MAX;
}

void solve()
{
    cin >> inp;
    mp.clear();

    for (size_t i{}; i < inp.size(); ++i)
        mp[inp[i]].push_back(i);

    size_t res{INT_MAX};

    res = min(helper('2', '5'), min(helper('5', '0'), helper('7', '5')));
    
    size_t sz{mp['0'].size()};
    if(sz >= 2)
        res = min(res, inp.size() - mp['0'][sz - 2] - 2);

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;

    while (t--)
        solve();

    return 0;
}