#include <bits/stdc++.h>
using namespace std;

int main() {
    int N{};
    cin >> N;
    vector<int> stones(N);
    vector<int> dp(N);    
    
    cin >> stones[0];
    dp[0] = 0;


    for(int i{1}; i < N; ++i) {
        cin >> stones[i];

        if(i == 1) {
            dp[i] = abs(stones[i] - stones[0]);
        }
        else {
            dp[i] = min(dp[i - 1] + abs(stones[i] - stones[i - 1]), 
            dp[i - 2] + abs(stones[i] - stones[i - 2]));
        }
    }

    cout << dp[N - 1] << '\n';
}