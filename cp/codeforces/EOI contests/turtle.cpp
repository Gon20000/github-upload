#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll turtle{}, hare{}, c{}, res{};
    cin >> turtle >> hare >> c;

    for(ll time{};; ++time) {
        ll turtle_d {turtle * time};
        ll hare_d {(hare * max(0ll, time - c))};

        if (hare_d > turtle_d)
            break;
        
        res = turtle_d;
    }

    cout << res << '\n';

    return 0;
}