#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;

    vector<ll> d{-INT_MAX};
    while(n--) {
        ll x{};
        cin >> x;

        if(x > d[d.size() - 1])
            d.push_back(x);
        else {
            auto lower {lower_bound(d.begin(), d.end(), x)};
            *lower = x;
        }
    }

    cout << d.size() - 1;

    return 0;
}