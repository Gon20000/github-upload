#include <bits/stdc++.h>
using namespace std;

const int max_size{100001};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
int dp[max_size];
int arr[max_size];
    memset(dp, 0, max_size * 2);

    int n{}, k{};
    cin >> n >> k;

    for(int i{}; i < n; ++i) {
        cin >> arr[i];

        if(i >= 1) 
            dp[i] = INT_MAX;
            
        for(int j{1}; j <= min(i, k); ++j) {
            dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
        }
    }

    cout << dp[n - 1] << '\n';
}