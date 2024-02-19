#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll mod {ll(1e9+7)};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n{};
    cin >> n;
 
    vector<ll> res(n + 1);
 
 
    for(int i{1}; i <= n; ++i) {
        if(i <= 6)
            ++res[i];
        for(int j{1}; j + i <= n && j <= 6; ++j) {
            res[i + j] = ((res[i] % mod) + (res[i+ j] % mod)) % mod;
 
 
        }
    }
 
    cout << res[n] % mod << '\n';
    return 0;
}