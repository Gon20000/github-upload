#include <bits/stdc++.h>
using namespace std;

vector<string> grid(2);
int n{};
vector<vector<int>> dp(2);

int visit(int x, int y) {
    if(x > 2 || y >= n)
        return 0;
    else if(dp[x][y])
        return dp[x][y];

    if(x == 1)
        return dp[x][y] = visit(x, y + 1);
    else if(y < n - 1) {
        if(grid[x + 1][y] == grid[x][y + 1])
            return dp[x][y] = visit(x + 1, y) + visit(x, y + 1);
        else if(grid[x + 1][y] < grid[x][y + 1])
            return dp[x][y] = visit(x + 1,y);
        else
            return dp[x][y] = visit(x, y + 1); 
    }
    else
        return dp[x][y] = visit(x + 1, y);
}

void solve() {
    dp.clear();
    dp.resize(2);
    cin >> n;

    for(int i{}; i < 2; ++i) {
        cin >> grid[i];
        dp[i].resize(n);
    }    

    dp[1][n - 1] = 1;    
    visit(0, 0);

    cout << dp[0][0] << '\n';
}

int main() {
    int t{};
    cin >> t;
    //freopen("out.txt", "w", stdout);
    while(t--)
        solve();

    return 0;    
}