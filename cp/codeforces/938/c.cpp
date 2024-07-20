#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n{}, k{};
    cin >> n >> k;

    vector<ll> arr(n);
    for (ll &x : arr)
        cin >> x;

    ll l{ceil(k / 2.0)}, r{k / 2}, res{};
    ll L{}, R{n - 1};

    while (l > 0 || r > 0)
    {

        if (L > R)
            break;

        if (arr[L] <= l && arr[L] > 0)
        {
            l -= arr[L];
            arr[L] = 0;
            ++res;
            ++L;
        }
        else if (l > 0 && arr[L] > l)
        {
            arr[L] -= l;
            l = 0;
        }

        if (arr[R] <= r && arr[R] > 0)
        {
            r -= arr[R];
            arr[R] = 0;
            ++res;
            --R;
        }
        else if (r > 0 && arr[R] > r)
        {
            arr[R] -= r;
            r = 0;
        }
    }

    cout << res << '\n';
}

int main()
{
    int t{};
    cin >> t;

    while (t--)
    {
        solve();
    }
}
