#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n{};
    cin >> n;
    
    map<ll, ll> mp{};
    ll res{};
    
    while(n--) {
        ll e{};
        cin >> e;
        
        if(e > 1 && (3 * e) % (e - 1) == 0 && mp.count((3 * e) / (e - 1)) > 0)
            res += mp[(3 * e) / (e - 1)];
            
        ++mp[e];
    }
    
    cout << res << '\n';
}

int main() {
	// your code goes here
    int t{};
    cin >> t;
    
    while(t--)
        solve();
        
        return 0;
}
