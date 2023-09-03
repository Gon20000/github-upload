#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);

    int n{}, res{};
    cin  >> n;
    unordered_map<string, unordered_set<string>> cities{};

    while(n--) {
        string first{}, second{};
        cin >> first >> second;
        first = first.substr(0, 2);

        if(cities.find(first) != cities.end() && cities[first].count(second) == 1)
            ++res;
          
        if(cities.find(second) == cities.end()) {
            cities[second] = unordered_set<string>{};
        }
        cities[second].insert(first);
    }

    cout << res << '\n';

    return 0;
}