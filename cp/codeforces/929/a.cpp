#include <bits/stdc++.h>
using namespace std;

int max_pos(const vector<int>& arr) {
    int max_so_far{arr[0]};
    int curr{arr[0]};

    for(int i{1}; i < arr.size(); ++i) {
        curr = max(curr, 0);
        curr += arr[i];
        
        max_so_far = max(curr, max_so_far);
    }

    return max_so_far;
}

void solve() {
    int n{};
    cin >> n;
    vector<int> arr(n);
    for(int i{}; i < n; ++i)
        cin >> arr[i];
    
    int res{};

    res = max(res, max_pos(arr));

    sort(arr.begin(), arr.end());

    int curr{};
    for(int i{}; i < arr.size(); ++i) {
        curr += abs(arr[i]);
    }
    res = max(res, curr);

    cout << res << '\n';

}

int main() {
    int t{};
    cin >> t;

    freopen("out.txt", "w", stdout);

    while(t--)
        solve();

    return 0;
}