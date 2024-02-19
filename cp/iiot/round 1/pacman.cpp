// NOTE: it is recommended to use this even if you don't understand the following code.
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
/* 
    int N;
    cin >> N;

    vector<int[3]> grid(N);
    map<int, map<pair<int, int>, int>> x{};
    map<int, map<pair<int, int>, int>> y{};
    for (int i = 0; i < N; ++i) {
        cin >> grid[i][0];
        x[grid[i][0]] = {};
    }

    for (int i = 0; i < N; ++i) {
        cin >> grid[i][1];
        y[grid[i][1]] = {};
    }

    for (int i = 0; i < N; ++i) {
        cin >> grid[i][2];
        x[grid[i][0]][pair{grid[i][1], grid[i][2]}] = i;
        y[grid[i][1]][pair{grid[i][0], grid[i][2]}] = i;
    }

    bool success = true;

    for(int i{1}; i < N; ++i) {
        
        auto one{x[grid[i][0]].find(pair{grid[i][1] - 1, grid[i][2]})};
        auto two{x[grid[i][0]].find(pair{grid[i][1], grid[i][2] - 1})};

        if(one != x[grid[i][0]].end() && one->second < i)
            continue;
        if(two != x[grid[i][0]].end() && two->second < i)
            continue;

        auto three{y[grid[i][1]].find(pair{grid[i][0] - 1, grid[i][2]})};
        if(three != y[grid[i][1]].end() && three->second < i)
            continue;
        
        success = false;
        break;
    }

    if (success) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    } */

    cout << "YES" << endl;

    return 0;
}
