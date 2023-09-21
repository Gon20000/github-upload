#include <bits/stdc++.h>
using namespace std;

int test(int x, int y, int k) {
    int res{INT_MAX};
    res = min(res, k - x + 1);
    
    if (y > 1)
        res = min(res, x - y + 1);

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, k{};
    cin >> n >> k;
    
    long long res{};
    vector<int> lock(n);
    for(int i{}; i < n; ++i) {
        cin >> lock[i];
    }

    for(int i{1}; i < n; ++i) {
        if (lock[i - 1] >= lock[i])
            res += test(lock[i - 1], lock[i], k);
    }

    cout << res << '\n';
}
