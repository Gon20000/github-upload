#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int max_size{1000001};
 
 
int main() {
    size_t n{}, x{};
    cin >> n >> x;
 
    vector<int> coins{0};
    vector<vector<ll>> dp(x + 1);
 
    for(int i{}; i < n; ++i) {
        dp[0].push_back(1);
        int coin{};
        cin >> coin;
        coins.push_back(coin);
    }
    dp[0].push_back(1);
 
    for(int i{1}; i <= x; ++i) {
        for(int j{}; j <= n; ++j) {
            dp[i].push_back(0);
        }
    }
 
    sort(coins.begin(), coins.end());
 
    for(int i{1}; i <= x; ++i) {
        for(int j{1}; j <= n; ++j) {
            if(i - coins[j] < 0)
                dp[i][j] += (dp[i][j - 1]);
            else
                dp[i][j] += (dp[i][j - 1] + dp[i - coins[j]][j]);
            
            dp[i][j] %= 1000000007ll;
        }
    }
 
    cout << dp[x][n] << '\n';
 
    return 0;
}