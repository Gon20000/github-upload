#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n{}, r{};
    cin >> n >> r;

    vector<ll> res{};
    ll output{};

    for(int i{0}; i < n; ++i) {
        res.push_back((r % 100) + 1);
        r = (6807 * r + 2831) % 201701; 
    }

    sort(res.begin(), res.end());

    output += res[0];
    for(int i{1}; i < n; ++i) {
        res[i] += res[i - 1];
        output += res[i];
    }

    cout << output << '\n';

    return 0;
}