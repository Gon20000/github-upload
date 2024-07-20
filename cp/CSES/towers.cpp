#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n{};
    cin >> n;

    map<int, int> res{};
    ll out{};
    while (n--)
    {
        int x{};
        cin >> x;

        auto it{res.upper_bound(x)};
        if (it != res.end())
        {
            --res[it->first];
            
            if (!res[it->first])
                res.erase(it->first);
            --out;
        }

        ++res[x];
        ++out;
    }

    cout << out << '\n';
    return 0;
}