#include <bits/stdc++.h>
using namespace std;

const int max_n{static_cast<int>(1e6 + 1)};
int sparse[21][max_n];

int k_step(int num, int k) {
    int cnt{}, curr{-INT_MAX};
    while(k > 0) {
        if(curr == -1)
            return -1;

        if(k & 1 == 1) {
            if(curr == -INT_MAX) {
                curr = sparse[cnt][num];
            }
            else
                curr = sparse[cnt][curr];
        }

        ++cnt;
        k >>= 1;
    }

    return curr;
}

int main() {
    int n{}, q{};
    cin >> n >> q;
    memset(sparse, -1, sizeof(sparse));

    for(int i{}; i < n - 1; ++i) {
        int x{}, y{};
        cin >> x >> y;
        if(x > y)
            swap(x, y);

        sparse[0][y] = x;
    }

    for(int i{1}; i < 21; ++i) {
        for(int node{1}; node < n; ++node) {
            int prev{sparse[i - 1][node]};
            
            if(prev != -1)
                sparse[i][node] = sparse[i - 1][prev];
        }
    }


    for(int i{}; i < n - 1; ++i)
        cout << k_step(i, q) << ' ';

    cout << k_step(n - 1, q) << '\n';

    return 0;
}