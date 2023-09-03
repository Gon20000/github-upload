#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n{};
    long long res{};
    cin >> n;
    unordered_map<int, int> a{};
    int arr[n];
    for(int i{}; i < 3; ++i) {
        int x{};
        for(int j{}; j < n; ++j) {
            cin >> x;
            if(i == 0) 
                ++a[x];
            else if(i == 1) {
                arr[j] = x;
            }
            else {
                res += a[arr[x - 1]];
            }
        }
    }

    std::cout << res << '\n';
}