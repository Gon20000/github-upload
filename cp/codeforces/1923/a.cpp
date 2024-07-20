#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n{};
    cin >> n;

    int first{-1}, last{};
    int res{};
    vector<char> inp(n);
    for(int i{}; i < n; ++i) {
        cin >> inp[i];

        if(inp[i] == '1' && first < 0)
            first = i;
        else if(inp[i] == '1')
            last = i;
        }
    
    if(!last) 
        cout << 0 << '\n';
    else {
        for (int i = first; i < last; i++)
        {
            if(inp[i] == '0')
                ++res;
        }
        cout << res << '\n';
    }
}

int main() {
    int t{};
    cin >> t;
    while(t--) {
        solve();
    }
}