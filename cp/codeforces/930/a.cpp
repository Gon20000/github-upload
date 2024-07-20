#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t{};
    cin >> t;

    while(t--) {
       ll x{};
       cin >>x;

        cout << (1ll << static_cast<ll>(log2(x))) << '\n';
    }

    return 0;
}