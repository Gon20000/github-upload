#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;

    while(t--) {
        ll n{}, m{}, res{};
        set<ll> a{};
        cin >> n >> m;

        if (n % m == 0) {
            cout << res << '\n';
            continue;
        }
        else if(m % 2 == 1 || (m % n == 0 && (m / n) % 2 == 1)) {
            cout << -1 << '\n';
            continue;
        }

        while(n % m > 0) {
            res += n % m;
            n = (n % m) * 2;
            if(a.count(n) == 1) {
                res = -1;
                break;
            }
            a.insert(n);
        }

        cout << res << '\n';
    }
}