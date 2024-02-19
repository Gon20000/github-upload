#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;

    while(t--) {
        int n{};
        cin >> n;
        
        ll sp{}, ep{};
        cin >> sp >> ep;
        bool res{true};

        for(int i{1}; i < n; ++i)  {
            ll si{}, ei{};
            cin >> si >> ei;

            if(si >= sp && ei >= ep) {
                res = false;
                break;
            }
        }

        cout << (res ? sp : -1) << '\n';
    }

    return 0;
}