#include <bits/stdc++.h>
using namespace std;

bool check(int mod, vector<int>& arr) {
    for(int x : arr)
        if(x % 3 == mod)
            return true;
    
    return false;
}

void solve() {
    int n{};
    cin >> n;
    vector<int> arr(n);
    int sum{};

    for(int i{}; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
        sum %= 3;
    }

    if(sum == 0) {
        cout << 0 << '\n';
        return;
    }

    if(sum == 2 || check(sum, arr)) {
        cout << 1 << '\n';
    }
    else 
        cout << 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;

    while(t--)
        solve();

    return 0;
}