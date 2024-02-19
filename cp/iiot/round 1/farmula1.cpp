// NOTE: it is recommended to use this even if you don't understand the following code.
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int T;
    cin >> T;
    vector<int> points{0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        
        ll score1{}, score2{};
        vector<int> P(N);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
            if(P[i] == 1)
                score2 += points[2];
            else
                score2 += points[1];
            
            if(P[i] < 11)
                score1 += points[P[i]];
        
        }
            cout << (score1 >= score2 ? "Champion" : "Practice harder") << endl;
                
    }

    return 0;
}
