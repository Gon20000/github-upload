#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n{}, k{};
    cin >> n >> k;

    vector<int> in(n);
    ll res{};

    for(int i{}; i < n - 1; ++i) {
        int x{}, y{};
        cin >> x  >> y;

        ++in[--y];
    }

    sort(in.begin(), in.end());    
    for(int i{}; i < n; ++i) {
        if(in[i] > k)
            break;
        
        k -= in[i];
        ++res;
    }

    cout << res << '\n';
}

int main() {
    int t{};
    cin >> t;
    freopen("a.out", "w", stdout);
    
    while(t--)
        solve();

    return 0;
}