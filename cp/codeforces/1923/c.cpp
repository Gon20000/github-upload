#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getSum(int l, int r, const vector<ll>& arr) {
    if(l == 0)
        return arr[r];
    
    return arr[r] - arr[l - 1];
}

bool check(ll sum, ll sum2, ll ones, ll other, int l, int r, const vector<ll>& inp) {
    ll diff{sum - sum2};
    if(diff == 0)
        return true;
    
    if(diff == 1)
        return ones > 0;
    else if(diff > 0) 
        return true;
    else {
        return diff + other >= 0;
    }
    
}

void solve() {
    int n{}, q{};
    cin >> n >> q;
    
    vector<ll> inp(n+1);
    vector<ll> inp2(n+1);
    vector<ll> psum(n+1);
    vector<ll> ones(n+1);
    vector<ll> neg(n+1);

    for(int i{}; i < n; ++i) {
        cin >> inp[i];
        psum[i] = inp[i] + psum[max(i - 1, 0)]; 
        inp2[i] = inp2[max(i - 1, 0)] + (inp[i] == 1 ? 2 : inp[i] - 1);
        ones[i] = ones[max(i - 1, 0)] + (inp[i] == 1 ? 1 : 0);
        neg[i] = neg[max(i - 1, 0)] + (inp[i] > 2 ? inp[i] - 2 : 0);
    }

    for(int i{}; i < q; ++i) {
        int l{}, r{};
        cin >> l >> r;

        --l;
        --r;

        if(l == r)
            cout << "NO\n";
        else

        cout << (check(getSum(l, r, psum), getSum(l, r, inp2), getSum(l, r, ones), getSum(l, r, neg), l, r, inp) ? "YES\n" : "NO\n");
    }
}

int main() {
    int t{};
    cin >> t;

    while(t--)
        solve();
}