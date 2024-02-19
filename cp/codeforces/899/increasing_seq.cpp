#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;

    while(t--) {
        ll res{0};
        int n{};
        cin >> n;

        while (n--) {
            ++res;            
            ll num{};
            cin >> num;

            if (res == num)
                ++res;
        }

        cout << res << '\n';
    }
}