#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n{}, k{}, res{};
    cin >> n >> k;

    vector<pair<int, int>> arr(n);
    multiset<int> curr{};

    for (int i{}; i < n; ++i)
    {
        int l{}, r{};
        cin >> l >> r;

        arr[i] = {0 - l,
                  0 - r};
    }

    sort(arr.begin(), arr.end(), [](pair<int, int> &first, pair<int, int> &second)
         { return second.second == first.second ? first.first < second.first : first.second > second.second; });

    for (auto [l, r] : arr)
    {
        // using normal upper bound gets a TLE lol, O(n) apparently
        auto it{curr.upper_bound(l)};
        if(it != curr.begin() && *prev(it) == l) {
            ++res;
            continue;
        }

        if (it != curr.end())
            curr.erase(it);

        if (curr.size() < k)
        {
            curr.insert(r);
            ++res;
        }
    }


    cout << res << '\n';
    return 0;
}