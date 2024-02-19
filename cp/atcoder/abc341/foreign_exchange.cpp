#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool compare(pair<ll, ll> first, pair<ll, ll> second) {
    return second.second == first.second ? first.first < second.first : second.second > first.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;
    vector<pair<ll, ll>> pairs(n);
    vector<ll> seq(n);

    for(int i{}; i < n; ++i) 
        cin >> seq[i];
    
    for(int i{}; i < n - 1; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end(), compare);

    for (size_t i = 0; i < n - 1; i++)
    {
        for(auto x : pairs) {
            if(x.first < seq[i]) {
                seq[i] -= x.first;
                seq[i + 1] += x.second;
            }
        }
    }
    
    cout << seq[n - 1] << '\n';
    
    return 0;
}