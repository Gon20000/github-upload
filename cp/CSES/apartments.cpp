#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n{}, m{}, k{}, res{};
    cin >> n >> m >> k;

    vector<int> people(n), apartments(m);
    for (int i{}; i < n; ++i)
        cin >> people[i];
    for (int j{}; j < m; ++j)
        cin >> apartments[j];

    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());

    auto it{apartments.begin()};
    for (auto person : people)
    {
        it = lower_bound(it, apartments.end(), person - k);

        if (it == apartments.end())
            break;

        if (abs(person - *it) <= k)
        {
            ++res;
            ++it;
        }
    }

    cout << res << '\n';
    return 0;
}