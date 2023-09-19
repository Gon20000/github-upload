#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, res{};
    cin >> n;
    vector<int> rem(n, -1);
    vector<int> rem_psum(n + 1, 0);
    vector<ll> input(n + 1, 0);

    rem[0] = 0;


    for(int i{1}; i <= n; ++i) {
        ll curr{};
        cin >> curr;

        input[i] = (input[i - 1] + curr);
        rem_psum[i] = (((rem_psum[i - 1] + curr) % n) + n) % n;
         
        if (rem[rem_psum[i]] == -1) 
            rem[rem_psum[i]] = i;
        else {
            ++res;
            if (input[i] == 0 || input[rem[rem_psum[i]]] % n == 0) 
                res += (i - rem[rem_psum[i]]);
        }
    }

    cout << res << '\n';

    return 0;
}