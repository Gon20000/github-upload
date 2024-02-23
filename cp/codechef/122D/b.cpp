#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n{};
    cin >> n;
    bool res{true};
    
    while(n--) {
        int x{};
        cin >> x;
        
        if(x < 5)
            res = false;
    }
    
    cout << (res ? "YES" : "NO") << '\n';
}

int main() {
	int t{};
	cin >> t;
	while(t--)  
	    solve();
}
