#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, k{};
    cin >> n >> k;
    
    unordered_map<ll, ll> cntPrefix{};

    ll sumSoFar{};
    ll res{};

    for(int i{}; i < n; ++i) {
        ll element{};
        cin >> element;

        sumSoFar += element;
        if (sumSoFar == k)
            ++res;

        res += cntPrefix[sumSoFar - k]; // psum[y] - psum[x] = k, then psum[y] - k = psum[x] 
        ++cntPrefix[sumSoFar];
    }  

    cout << res << '\n';

    return 0;
}