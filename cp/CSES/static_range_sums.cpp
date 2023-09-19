#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> arr{};


int main() {
    int n{}, q{};
    cin >> n >> q;

    arr.resize(n + 1);
    
    for(int i{1}; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];   
    }

    while (q--) {
        int x{}, y{};
        cin >> x >> y;

        cout << arr[y] - arr[x - 1] << '\n';
    }
    return 0;
}