#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n{};
    cin >> n;

    vector<int> arr(n);
    for(int& x : arr)
        cin >> x;
    
    sort(arr.begin(), arr.end());

    int mid{ceil(arr.size() / 2.0) - 1};
    int med{arr[mid] + 1};
    int res{};

    for(; mid < n; ++mid) {
        if(arr[mid] < med)
            ++res;
        else
            break;
    }

    cout << res << '\n';
}

int main() {
    int t{};
    cin >> t;

    while(t--)
        solve();

    return 0;
}