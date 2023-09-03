#include <bits/stdc++.h>
using namespace std;

constexpr int cow_size{8};
using cows_t = array<string, cow_size>;

map<string, vector<string>> names { 
        {"Beatrice", {}},
        {"Belinda", {}},
        {"Bella", {}}, 
        {"Bessie", {}}, 
        {"Betsy", {}}, 
        {"Blue", {}}, 
        {"Buttercup", {}}, 
        {"Sue", {}}
};

bool checkMap(int ind, const cows_t& cows) {
    for(int i{}; i < names[cows[ind]].size(); ++i) {
        if(cows[ind - 1] != names[cows[ind]][i] && cows[ind + 1] != names[cows[ind]][i])
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    cows_t cows {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    int N{};
    string first{}, tmp{}, second{};
    cin >> N;

    for(; N > 0; --N) {
        cin >> first >> tmp >> tmp >> tmp >> tmp >> second;
        names[first].push_back(second);
        names[second].push_back(first);
    }

    do {
        bool check{ true };
        for(int i{}; i < cow_size; ++i) {
            int size{names[cows[i]].size()};
            if (((i == 0 || i == cow_size - 1) && size > 1)
                || checkMap(i, cows)) {
                check = false;
                break;
            }
        }
        
         if (check) {
            for(string cow : cows)
                cout << cow << '\n';
            break;
         }
    }
    while (next_permutation(cows.begin(), cows.end()));
}