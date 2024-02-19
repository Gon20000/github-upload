// NOTE: it is recommended to use this even if you don't understand the following code.
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        
        int Q;
        cin >> Q;
        
        vector<int> L(Q), R(Q);
        for (int i = 0; i < Q; ++i) {
            int res{};
            int l{}, r{};
            cin >> l >> r;
            --l;
            --r;
            for(; l <= r; ++l) {
                ++res;
                int m{2};
                for(int k{l + 1}; k <= r && A[k] % m == 0; ++k) {
                    ++res;
                    ++m;
                }
            }
            cout << res << '\n';
        }
        
            
    }

    return 0;
}
