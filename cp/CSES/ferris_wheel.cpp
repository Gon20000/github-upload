#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n{}, x{};
    cin >> n >> x;

    vector<int> weights(n);
    for (int i{}; i < n; ++i)
    {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());

    auto end{upper_bound(weights.begin(), weights.end(), x - weights[0])};
    ll res{distance(end, weights.end())};

    for (auto it{weights.begin()}; it != end--; ++it)
    {
        while (it != end && *it + *end >  x)
        {
            --end;
            ++res;
        }

        ++res;
        if(it == end)
            break;
    }

    cout << res << '\n';
    return 0;
}