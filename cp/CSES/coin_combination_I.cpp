#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int max_size{1000001};
vector<ll> dp(max_size);


int main() {
    int n{}, x{};
    cin >> n >> x;

    vector<int> coins{};
    
    while (n--) {
        int coin{};
        cin >> coin;
        coins.push_back(coin);
        ++dp[coin];
    }

    for(int i{}; i <= x; ++i) {
        if(dp[i] == 0)
            continue;

        for(int j{}; j < coins.size(); ++j) {
            if(i + coins[j] <= x) {
                dp[i + coins[j]] += dp[i];
                dp[i + coins[j]] %= 1000000007ll;
            }
        }
    }

    cout << dp[x] << '\n';

    return 0;
}
