#include <bits/stdc++.h>
using namespace std;

int main() {
    int n{};
    cin >> n;
    map<int, int> m{};
    for(int i{}; i < n; ++i) {
        int x{};
        cin >> x;
        m[x] = i;
    }

    int q{};
    cin >> q;

    while(q--) {
        int x{}, y{};
        cin >> x >> y;
        if(m[x] < m[y])
            cout << x << '\n';
        else
            cout << y << '\n';
    }
    
    return 0;
}