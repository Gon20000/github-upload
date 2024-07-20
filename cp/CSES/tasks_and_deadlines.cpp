#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n{};
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(auto& x : arr)
        cin >> x.first >> x.second;

    sort(arr.begin(), arr.end());    

    ll res{}, curr{};
    for(const auto& x : arr) {
        curr += x.first;
        res += x.second - curr;
    }

    cout << res << '\n';
    return 0;
}