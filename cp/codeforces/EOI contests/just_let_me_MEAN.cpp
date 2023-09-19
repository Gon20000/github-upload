#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int T{};
    cin >> T;
    
    while (T--) {
        ll n{}, x{}, sum{};
        cin >> n >> x;
        
        for (int i{}; i < n; ++i) {
            ll num{};
            cin >> num;

            sum += num;
        }
        
        cout << (sum <= (n + 1) * x ? "YES\n" : "NO\n");
    }
}