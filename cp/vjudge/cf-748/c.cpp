#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n{}, k{};
    cin >> n >> k;

    int cat{0};
    ll res{};
    vector<int> mice(k);
    for(int& x : mice)
        cin >> x;

    sort(mice.begin(), mice.end());

    for(int i{mice.size() - 1}; i >= 0; --i) {
        if(mice[i] <= cat)
            break;

        cat += n - mice[i];
        ++res;    
    }     

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    cin >> t;

    while(t--)
        solve();
        
    return 0;
}