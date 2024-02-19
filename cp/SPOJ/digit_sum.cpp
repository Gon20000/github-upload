#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// dp[n][above][under]
pair<ll, ll> dp[19][2][2];
string l{}, r{};

void reset() {
    for(auto& w : dp) {
        for(auto& x : w) {
            for(auto& y : x) {
                y = {-1, -1};
            }
        }
    }
}

int digit(const string& str, int idx) {
    return str[idx] - '0';
}

pair<ll, ll> solve(size_t pos, bool above, bool under) {
    if(pos == r.size()) {
        return {0, 1};
    }

    if(dp[pos][above][under].first != -1)
        return dp[pos][above][under]; 

    int right{under ? 9 : digit(r, pos)};
    int left{above ? 0 : digit(l, pos)};

    pair<ll, ll> res{};
    for(; right >= left; --right) {
        bool newAbove{above || right > left};
        bool newUnder{under || right < digit(r, pos)};

        
        pair<ll, ll> curr{solve(pos + 1, newAbove, newUnder)};
        curr.first += right * max(curr.second, 1ll);
        res.first += curr.first;
        res.second += curr.second;
    }

    return dp[pos][above][under] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n{};
    cin >> n;

    while(n--) {
        reset();
        cin >> l >> r;

        while(l.size() < r.size()) {
            l = "0" + l;
        }

        cout << solve(0, false, false).first << '\n';
    }

    return 0;
}