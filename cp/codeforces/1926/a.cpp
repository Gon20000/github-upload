#include <bits/stdc++.h>
using namespace std;

int main() {
    int n{};
    cin >> n;
    while(n--) {
        int x{}, y{};
        for(int i{}; i < 5; ++i) {
            char a{};
            cin >> a;
            if(a == 'A')
                ++x;
            else
                ++y;
        }

        cout << (x > y ? "A" : "B") << '\n'; 
    }
    return 0;
}