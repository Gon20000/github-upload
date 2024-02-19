#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(const multiset<ll>& a, const multiset<ll>& b) {
    return *(a.begin()) < *(--b.end());
}

void exchange(multiset<ll>& a, multiset<ll>& b) {
    ll first{*(a.begin())};
    ll second{*(--b.end())};

    a.erase(a.begin());
    b.erase(--b.end());
    a.insert(second);
    b.insert(first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;

    while(t--) {
        
        ll n{}, m{}, k{};
        cin >> n >> m >> k;

        ll jfish{};
        multiset<ll> fish1{};
        multiset<ll> fish2{};

        while(n--) {
            ll x{};
            cin >> x;
            
            jfish += x;
            fish1.insert(x);
        }

        while (m--) {
            ll x{};
            cin >> x;
            
            fish2.insert(x);
        }

        ll first{*(fish1.begin())};
        ll second{*(--fish2.end())};
        if (k % 2  && first < second) {

            jfish += second - first;
        }

        cout << jfish << '\n';
    }
}