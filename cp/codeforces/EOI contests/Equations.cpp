#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    for (int i{}; i < 10; ++i)
    {
        ll a{}, b{};
        cin >> a >> b;

        ll low{INT_MAX}, high{INT_MIN}, size{};

        for (ll x{}; x <= a && 4 * x <= b; ++x)
        {
            for (ll y{}; 2 * y <= a && 5 * y <= b; ++y)
            {
                ll e{(a - x - 2 * y)};
                if (e < 0)
                    break;
                if (e % 3 == 0 && e / 3 == (b - 4 * x - 5 * y) / 6.0)
                {
                    low = min(low, e / 3);
                    high = max(high, e / 3);
                    ++size;
                }
            }
        }

        if (low == INT_MAX || high == INT_MIN)
            cout << "No Solutions.\n";
        else
            cout << low << ' ' << high << ' ' << size << '\n';
    }

    return 0;
}