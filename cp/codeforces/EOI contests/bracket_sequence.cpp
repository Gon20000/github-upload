#include <bits/stdc++.h>
using namespace std;

int main() {
    int T{};
    cin >> T;

    while (T--) {
        int x{};
        cin >> x;

        int power{static_cast<int>(log2(x))};
        array<string, 3> res{};

        for( int i{power + 1}; i > 0 && x > 1; --i) {
            res[2] = '(' + res[2] + ')';
        }

        for (int i = x - (1 << power) - x%2; i > 0; i /= 2)
        {
            res[1] = '(' + res[1] + ')';
        }
        
        if(x % 2 > 0) 
            res[0] = "()";
        
        for(int i{}; i < 3; ++i) {
            cout << res[i];
        }

        cout << '\n';
    }

    return 0;
}