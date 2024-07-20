#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n{};
    cin >> n;

    vector<int> arr(n);
    for(int i{}; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll res{};
    for(int x : arr) {
        res += abs(x - arr[n / 2]);
    }

    cout << res << '\n';

    return 0;
}

