#include <bits/stdc++.h>
using namespace std;

using memo_t = map<pair<int, int>, int>;
using ll = long long;


int solve(vector<vector<int>>& grid, int i, int j, memo_t& memo, ll sum) {
    if(i < 0 || j <0)
        return INT_MAX;
    else if(i == 0 && j == 0)
        return grid[i][j];
        
    pair<int, int> curr {i, j};

    if(memo.find(curr) != memo.end() )
        return memo[curr];
    

    memo[curr] = grid[i][j] + min(solve(grid, i - 1, j, memo, sum), solve(grid, i, j - 1, memo, sum));
    return memo[curr];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    memo_t memo{};
    cout << solve(grid, grid.size() - 1, grid[0].size() - 1, memo, 0) << endl;

    return 0;
}
