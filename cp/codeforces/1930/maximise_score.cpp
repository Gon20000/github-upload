#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin >> t;
    while(t--) {
        int n{};
        cin >> n;

        vector<long long> inp(2*n);
        for(int i{}; i < 2*n; ++i) {
            cin >> inp[i];
        }

        sort(inp.begin(), inp.end());
        long long res{};
        for(int i{}; i < n; ++i) {
            res += inp[2*i];
        }

        cout << res << '\n';
    }

    return 0;
}