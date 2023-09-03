#include <bits/stdc++.h>
using namespace std;

constexpr int n{ 3 };
using grid_t = unordered_set<char>[2 * n + 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    unordered_set<char> res1{};
    vector<pair<char,char>> res2{};
    grid_t grid;
    for(int i{}; i < n; ++i) {
        for(int j{}; j < n; ++j) {
            char x{};
            cin >> x;
            grid[i].insert(x);
            grid[n+j].insert(x); //horizontal

            if(i == j) {
                grid[2*n].insert(x);
            }
            if(i + j == n - 1) {
                grid[2*n+1].insert(x);
            }
        }
    }

    for(auto x : grid) {
        if(x.size() == 1) {
            res1.insert(*x.begin());
        }
        else if(x.size() == 2) {
            auto it{ x.begin() };
            pair<char, char> p{*it, *(++it)};
            bool a{true};
            for(pair<char, char> y : res2) {
                if(p == y || (p.first == y.second && p.second == y.first)) {
                    a = false;
                    break;
                }
            }
            if(a)
                res2.push_back(p);
        }
    }

    cout << res1.size() << '\n' << res2.size() << '\n';

    return 0;
}