#include <bits/stdc++.h>
using namespace std;

int main() {
    int N{};
    cin >> N;
    int stones[N];
    int dp[N];    
    
    cin >> stones[0];
    dp[0] = stones[0];


    for(int i{1}; i < N; ++i) {
        int cost{};
        cin >> cost;
        stones[i] = cost;
        if(i == 1) {
            dp[i] = abs(stones[i] - stones[0]);
        }
    }
}