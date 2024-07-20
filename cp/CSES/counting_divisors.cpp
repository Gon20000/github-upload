#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x{};
    cin >> x;
    
    ll lim{static_cast<ll>(ceil(sqrt(x)))};

    int res{1};
    for(int i{2}; i <= lim; ++i) {
        int curr{1};
        while(x % i == 0) {
            x /= i;
            ++curr; 
        }

        res *= curr;
    } 

    if(x != 1)
        res *= 2;

    cout << (lim == 1 ? 1 : max(res, 2)) << '\n';
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