#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n{};
    cin >> n;

    int mini{}, cnt{}, res{};
    
    while(n--) {
        int x{};
        cin >> x;

        if(x > mini) {
            mini = x;
            ++cnt;
        }
        else {
            if(cnt >= 3)
                ++res;
            cnt = 1;
            mini = x;    
        }
    }

    if(cnt >= 3)
        ++res;

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{1};
    //cin >> t;
   
    while(t--)
        solve();
    
    return 0;
}