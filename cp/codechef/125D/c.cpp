#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n{};
    cin >> n;

    int curr{-1}, maxCurr{}, res{};
    for (int i{}; i < n; ++i)
    {
        char x{};
        cin >> x;

        if (x == '1')
        {
            if (curr != -1)
            {
                maxCurr = max(maxCurr, i - curr);
                curr = -1;
            }
            ++res;
        }
        else
        {
            if (curr == -1)
                curr = i;
        }
    }
    if (curr != -1)
    {
        maxCurr = max(maxCurr, n - curr);
        curr = -1;
    }

    cout << (res + maxCurr) << '\n';
}

int main()
{
    int t{};
    cin >> t;
    while (t--)
        solve();

    return 0;
}
