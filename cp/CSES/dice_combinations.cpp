#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;

    vector<int> res(n + 1);

    for(int i{0}; i < n; ++i) {
        for(int j{i + 1}; j <= min(i + 6, n); ++j) {
            res[j] += res[i];
            if(i + j <= 6)
                ++res[j];
        }
    }

    cout << res[n] << '\n';
    return 0;
}