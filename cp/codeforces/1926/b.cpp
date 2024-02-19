#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n{};
    cin >> n;

    int prev{};
    int res{0};
    for(int i{}; i < n; ++i) {
        int curr{};
        for(int j{}; j < n; ++j) {
            char x{};
            cin >> x;
            if(x == '1')
                ++curr;
        }
        if(prev == 0)
            prev = curr;
        else if(res == 0) {
            res = (prev == curr) ? 1 : 2;
        }
    }
    cout << (res < 2 ? "SQUARE" : "TRIANGLE") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while(t--)
        solve();

    return 0;
}