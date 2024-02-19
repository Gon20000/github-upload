#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using node_t = pair<ll, ll>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // reset arr and psum

    ll n{}, q{};
    cin >> n >> q;

    vector<vector<node_t>> arr(n + 1);
    vector<ll> psum(n + 1);

    for(int i{1}; i <= n; ++i) {
        ll x{};
        cin >> x;

        arr[0].push_back({2 * x, x});
        psum[i] = x + psum[i - 1];
    }

    for(int i{1}; i < n; ++i) {
        for(int j{1}; j < n - i + 1; ++j) {
            arr[i].push_back(
                {2 * (i + 1) * (psum[j + i] - psum[i - j]),
                    max(arr[i - 1][j].second, arr[i - 1][j - 1].second)});
        }
    }

/*     while(q--) {
        ll l{}, r{}, x{};
        cin  >> l  >> r  >>  x;
        ll res{query(1, 1, n, l, r, x)};
        if(res == LLONG_MAX)
            cout << -1;
        else
            cout << res << '\n';
    } */

    return 0;
}