#include <bits/stdc++.h>
using namespace std;

int index(string a) {
    switch(a[0]) {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'D':
            return 2;
        case 'E':
            return 3;
        case 'G':
            return 4;
        case 'H':
            return 5;
        case 'M':
            return 6;     
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout); 

    int N{};
    cin >> N;
    pair<string, int> cows[7] = {
        {"Annabelle",0},
        {"Bessie",0},
        {"Daisy",0},
        {"Elsie",0},  
        {"Gertie",0},
        {"Henrietta",0},
        {"Maggie",0},
    };

    while(N--) {
        string ind{};
        int x{};
        cin >> ind >> x;
        cows[index(ind)].second += x;
    }
    pair<string, int> minimum{"Bessie", static_cast<int>(INFINITY)};
    pair<string, int> min2{"Tie", 0};
    
    for(auto [name, x] : cows) {
        if(x < minimum.second) {
            min2 = minimum;
            minimum = {name, x};
        }
        else if(x > minimum.second && x < min2.second) {
            min2 = {name, x};
        }
        else if(min2.second == x) {
            min2.first = "Tie";
        }
    }

    std::cout << (min2.second == static_cast<int>(INFINITY) ? "Tie" : min2.first) << '\n'; 
    return 0;
}