#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n{}, x{};
    cin >> n >> x;

    vector<int> coins{};
    vector<ll> dp(x + 1, INT_MAX);
    dp[0] = 0;

    while (n--) {
        int coin{};
        cin >> coin;
        coins.push_back(coin);
    }

    for(int i{}; i <= x; ++i) {
        for(int j{}; j < coins.size(); ++j) {
            if(i + coins[j] <= x)
                dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';

    return 0;
}
