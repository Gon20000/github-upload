#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, pair<int, int>> x{};

    string str{};
    cin >> str;

    int i{};
    for(char chr : str) {
        x[chr];
        ++x[chr].first;
        x[chr].second = i++;
    }

    for(auto a : x) {
        if(a.second.first == 1)
            cout << a.second.second + 1 << '\n';
    }

    return 0;
}