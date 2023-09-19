#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll query(ll low, ll high, const vector<vector<ll>>& table) {
    // insert low as low -1 and high as high - 1
    if( low == high )
        return table[0][low];

    double power {log2(high - low + 1)};
    ll row{ static_cast<ll>(power) };
    return min(table[row][low], table[row][high - (1 << row) + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> table{};
    ll n{}, q{};
    cin >> n >> q;

    ll size  {static_cast<ll>(log2(n)) + 1};
    table.resize(size);
    
    for(ll i{}; i < n; ++i)  {
        ll x{};
        cin >> x;

        table[0].push_back(x);
    }

    for(ll j{1}; j < size; ++j) {
        for(ll i{}; i <= n - (1 << j); ++i) {
            table[j].push_back(min(table[j - 1][i], table[j - 1][i + j]));
        } 
    }

    while (q--) {
        ll low{}, high{};
        cin >> low >> high;

        cout << query(low - 1, high - 1, table) << '\n';
    }

    return 0;
}